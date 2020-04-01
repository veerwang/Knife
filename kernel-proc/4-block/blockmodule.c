// 快设备的例子
//https://www.xuebuyuan.com/3227084.html
//https://blog.csdn.net/cxy_chen/article/details/80998510

#include<linux/init.h>    //初始换函数
#include<linux/kernel.h>  //内核头文件
#include<linux/module.h>  //模块的头文件
#include<linux/blkdev.h>  //块设备的相关函数
#include <linux/hdreg.h>  //struct hd_geometry
#include<linux/vmalloc.h> //申请内存
MODULE_LICENSE("GPL");

#define SIMP_BLKDEV_DISKNAME        "ramblkdev"
#define SIMP_BLKDEV_DEVICEMAJOR     COMPAQ_SMART2_MAJOR
#define SIMP_BLKDEV_BYTES           (32*1024*1024)
#define SIMP_BLKDEV_MAXPARTITIONS   (1)  // 分区数目

// 一个扇区512个字节 >> 9

static struct gendisk *simp_blkdev_disk;
static struct request_queue *simp_blkdev_queue;
static void simp_blkdev_do_request(struct request_queue *q);
unsigned char *simp_blkdev_data;

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

static int __init blockmodule_start(void) {
	int ret;
	simp_blkdev_data = (unsigned char*)vmalloc(SIMP_BLKDEV_BYTES);
	if ( !simp_blkdev_data ) {
		ret = -ENOMEM;
		goto err_init_queue;
	}

	simp_blkdev_queue = blk_init_queue(simp_blkdev_do_request, NULL);
	if (!simp_blkdev_queue) {
		ret = -ENOMEM;
		goto err_init_queue;
	}
	//blk_queue_make_request(simp_blkdev_queue, simp_blkdev_make_request);

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
	// 以扇区为单位,因此要>>9
	set_capacity(simp_blkdev_disk, SIMP_BLKDEV_BYTES>>9);

	// 将块设备的结构体添加到系统中
	add_disk(simp_blkdev_disk);
    	printk(KERN_ALERT "Loading blockmodule...\n");
    	return 0;

err_alloc_disk:
        blk_cleanup_queue(simp_blkdev_queue);
err_init_queue:
        return ret;
}
 
static void __exit blockmodule_end(void)
{
	del_gendisk(simp_blkdev_disk);
	put_disk(simp_blkdev_disk);
	blk_cleanup_queue(simp_blkdev_queue);
	if (!simp_blkdev_data)
		vfree(simp_blkdev_data);
    	printk(KERN_ALERT "blockmodule release\n");
}

static void simp_blkdev_do_request(struct request_queue *q)
{
        struct request *req;
	struct bio *req_bio;// 当前请求的bio
	struct bio_vec *bvec;// 当前请求的bio的段(segment)链表

	char *disk_mem;      // 需要读/写的磁盘区域
	char *buffer;        // 磁盘块设备的请求在内存中的缓冲区
	int i = 0;

        while ((req = blk_fetch_request(q)) != NULL) {
                if ((blk_rq_pos(req) + blk_rq_cur_sectors(req)) << 9
                        > SIMP_BLKDEV_BYTES) {
                        printk(KERN_ERR SIMP_BLKDEV_DISKNAME
                                ": bad request: block=%llu, count=%u\n",
                                (unsigned long long)blk_rq_pos(req),
                                blk_rq_cur_sectors(req));
                        blk_end_request_all(req, -EIO);
                        continue;
                }


		disk_mem = simp_blkdev_data + (blk_rq_pos(req) << 9);
		req_bio = req->bio;// 获取当前请求的bio

                switch (rq_data_dir(req)) {
                case READ:
			while(req_bio != NULL) {
				//　for循环处理bio结构中的bio_vec结构体数组（bio_vec结构体数组代表一个完整的缓冲区）
				for( i=0; i<req_bio->bi_vcnt; i++ ) {
					bvec = &(req_bio->bi_io_vec[i]);
					buffer = kmap(bvec->bv_page) + bvec->bv_offset;
					memcpy(buffer, disk_mem, bvec->bv_len);
					kunmap(bvec->bv_page);
					disk_mem += bvec->bv_len;
				}
				req_bio = req_bio->bi_next;
			}
                        __blk_end_request_all(req, 0);
                        break;
                case WRITE:
			while(req_bio != NULL) {
				for(i=0; i<req_bio->bi_vcnt; i++) {
					bvec = &(req_bio->bi_io_vec[i]);
					buffer = kmap(bvec->bv_page) + bvec->bv_offset;
					memcpy(disk_mem, buffer, bvec->bv_len);
					kunmap(bvec->bv_page);
					disk_mem += bvec->bv_len;
				}
				req_bio = req_bio->bi_next;
			}
                        __blk_end_request_all(req, 0);
                        break;
                default:
                        //No default because rq_data_dir(req) is 1 bit 
                        break;
                }
        }
}

module_init(blockmodule_start);
module_exit(blockmodule_end);
