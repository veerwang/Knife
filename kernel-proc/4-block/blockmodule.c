// 快设备的例子
//https://www.xuebuyuan.com/3227084.html

#include<linux/init.h>    //初始换函数
#include<linux/kernel.h>  //内核头文件
#include<linux/module.h>  //模块的头文件
#include<linux/blkdev.h>  //块设备的相关函数
#include <linux/hdreg.h>  //struct hd_geometry
MODULE_LICENSE("GPL");

#define SIMP_BLKDEV_DISKNAME        "simp_blkdev"
#define SIMP_BLKDEV_DEVICEMAJOR     COMPAQ_SMART2_MAJOR
#define SIMP_BLKDEV_BYTES           (16*1024*1024)
#define SIMP_BLKDEV_MAXPARTITIONS   (64)  // 分区数目

static struct gendisk *simp_blkdev_disk;
static struct request_queue *simp_blkdev_queue;
static void simp_blkdev_do_request(struct request_queue *q);

static int simp_blkdev_getgeo(struct block_device *bdev,
                struct hd_geometry *geo)
{
        /*
         * capacity        heads        sectors        cylinders
         * 0~16M        1        1        0~32768
         * 16M~512M        1        32        1024~32768
         * 512M~16G        32        32        1024~32768
         * 16G~...        255        63        2088~...
         */
        if (SIMP_BLKDEV_BYTES < 16 * 1024 * 1024) {
                geo->heads = 1;
                geo->sectors = 1;

        } else if (SIMP_BLKDEV_BYTES < 512 * 1024 * 1024) {
                geo->heads = 1;
                geo->sectors = 32;
        } else if (SIMP_BLKDEV_BYTES < 16ULL * 1024 * 1024 * 1024) {
                geo->heads = 32;
                geo->sectors = 32;
        } else {
                geo->heads = 255;
                geo->sectors = 63;
        }

        geo->cylinders = SIMP_BLKDEV_BYTES>>9/geo->heads/geo->sectors;

        return 0;
}

struct block_device_operations simp_blkdev_fops = {
          .owner   = THIS_MODULE,
	  .getgeo  = simp_blkdev_getgeo,
};

static int simp_blkdev_make_request(struct request_queue *q, struct bio *bio)
{
        struct bio_vec *bvec;
        int i;
        unsigned long long dsk_offset;

        dsk_offset = bio->bi_sector * 512;

        bio_for_each_segment(bvec, bio, i) {
                unsigned int count_done, count_current;
                void *iovec_mem;
                void *dsk_mem;

                iovec_mem = kmap(bvec->bv_page) + bvec->bv_offset;

                count_done = 0;
                while (count_done < bvec->bv_len) {
                        count_current = min(bvec->bv_len - count_done, PAGE_SIZE - (dsk_offset + count_done) % PAGE_SIZE);

                        dsk_mem = radix_tree_lookup(&simp_blkdev_data, (dsk_offset + count_done) / PAGE_SIZE);
                        dsk_mem += (dsk_offset + count_done) % PAGE_SIZE;

                        switch (bio_rw(bio)) {
                        case READ:
                        case READA:
                                memcpy(iovec_mem + count_done, dsk_mem, count_current);
                                break;
                        case WRITE:
                                memcpy(dsk_mem, iovec_mem + count_done, count_current);
                                break;
                        }
                        count_done += count_current;
                }

                kunmap(bvec->bv_page);
                dsk_offset += bvec->bv_len;
        }

        bio_endio(bio, 0);
        return 0;
}

static int __init blockmodule_start(void) {
	int ret;
	simp_blkdev_queue = blk_init_queue(simp_blkdev_do_request, NULL);
	if (!simp_blkdev_queue) {
		ret = -ENOMEM;
		goto err_init_queue;
	}
	blk_queue_make_request(simp_blkdev_queue, simp_blkdev_make_request);

	// 申请一个块设备
	simp_blkdev_disk = alloc_disk(SIMP_BLKDEV_MAXPARTITIONS);
	if (!simp_blkdev_disk) {
		ret = -ENOMEM;
		goto err_alloc_disk;
	}

	strcpy(simp_blkdev_disk->disk_name, SIMP_BLKDEV_DISKNAME);
	simp_blkdev_disk->major = SIMP_BLKDEV_DEVICEMAJOR;
	simp_blkdev_disk->first_minor = 0;
	simp_blkdev_disk->fops = &simp_blkdev_fops;
	simp_blkdev_disk->queue = simp_blkdev_queue;
	set_capacity(simp_blkdev_disk, SIMP_BLKDEV_BYTES>>9);

	// 将块设备的结构体添加到系统中
	add_disk(simp_blkdev_disk);
    	printk(KERN_ALERT "Loading blockmodule...\n");
    	return 0;

err_alloc_diskmem:
        put_disk(simp_blkdev_disk);
err_alloc_disk:
        blk_cleanup_queue(simp_blkdev_queue);
err_alloc_queue:
        return ret;
}
 
static void __exit blockmodule_end(void)
{
	del_gendisk(simp_blkdev_disk);
	put_disk(simp_blkdev_disk);
	blk_cleanup_queue(simp_blkdev_queue);
    	printk(KERN_ALERT "blockmodule release\n");
}

static void simp_blkdev_do_request(struct request_queue *q)
{
        struct request *req;
        while ((req = elv_next_request(q)) != NULL) {
                if ((req->sector + req->current_nr_sectors) << 9
                        > SIMP_BLKDEV_BYTES) {
                        printk(KERN_ERR SIMP_BLKDEV_DISKNAME
                                ": bad request: block=%llu, count=%u\n",
                                (unsigned long long)req->sector,
                                req->current_nr_sectors);
                        end_request(req, 0);
                        continue;
                }

                switch (rq_data_dir(req)) {
                case READ:
                        memcpy(req->buffer,
                                simp_blkdev_data + (req->sector << 9),
                                req->current_nr_sectors << 9);
                        end_request(req, 1);
                        break;
                case WRITE:
                        memcpy(simp_blkdev_data + (req->sector << 9),
                                req->buffer, req->current_nr_sectors << 9);
                        end_request(req, 1);
                        break;
                default:
                        /* No default because rq_data_dir(req) is 1 bit */
                        break;
                }
        }
}

module_init(blockmodule_start);
module_exit(blockmodule_end);
