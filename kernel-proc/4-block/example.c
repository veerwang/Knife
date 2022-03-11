#include<linux/init.h>
#include<linux/module.h>
#include<linux/genhd.h>
#include<linux/fs.h>
#include<linux/blkdev.h>
#include<linux/bio.h>
 
#define SIMP_BLKDEV_DISKNAME "simp_blkdev"
#define SIMP_BLKDEV_DEVICEMAJOR COMPAQ_SMART2_MAJOR
#define SIMP_BLKDEV_BYTES (8*1024*1024)
 
static DEFINE_SPINLOCK(rq_lock);
unsigned char simp_blkdev_data[SIMP_BLKDEV_BYTES];
static struct gendisk *simp_blkdev_disk;
static struct request_queue *simp_blkdev_queue;//device's request queue
 
struct block_device_operations simp_blkdev_fops = {
    .owner = THIS_MODULE,
};
//handle bio
static int simp_blkdev_make_request(struct request_queue *q, struct bio *bio){
    struct bio_vec *bvec;
    int i;
    void *dsk_mem;
    if( (bio->bi_sector << 9) + bio->bi_size > SIMP_BLKDEV_BYTES){
        printk(KERN_ERR SIMP_BLKDEV_DISKNAME ":bad request:block=%llu,count=%u\n",(unsigned long long)bio->bi_sector,bio->bi_size);
        bio_endio(bio,-EIO);
    return 0;
    }
    dsk_mem = simp_blkdev_data + (bio->bi_sector << 9);
    bio_for_each_segment(bvec, bio, i){
        void *iovec_mem;
        switch( bio_rw(bio) ){
            case READ:
            case READA:
                iovec_mem = kmap(bvec->bv_page) + bvec->bv_offset;
                memcpy(iovec_mem, dsk_mem, bvec->bv_len);
                kunmap(bvec->bv_page);
                break;
            case WRITE:
                iovec_mem = kmap(bvec->bv_page) + bvec->bv_offset;
                memcpy(dsk_mem, iovec_mem, bvec->bv_len);
                kunmap(bvec->bv_page);
                break;
            default:
                printk(KERN_ERR SIMP_BLKDEV_DISKNAME ": unknown value of bio_rw: %lu\n",bio_rw(bio));
                bio_endio(bio,-EIO);
                return 0;
        }
        dsk_mem += bvec->bv_len;
    }
    bio_endio(bio,0);
    return 0;
}
 
 
static int simp_blkdev_init(void){
    int ret;
    simp_blkdev_queue = blk_alloc_queue(GFP_KERNEL);
    if(!simp_blkdev_queue){
        ret = -ENOMEM;
        goto error_alloc_queue;
    }
    blk_queue_make_request(simp_blkdev_queue, simp_blkdev_make_request);
    //alloc the resource of gendisk
    simp_blkdev_disk = alloc_disk(1);
    if(!simp_blkdev_disk){
        ret = -ENOMEM;
        goto error_alloc_disk;
    }
    
 
    //populate the gendisk structure
    strcpy(simp_blkdev_disk->disk_name,SIMP_BLKDEV_DISKNAME);
    simp_blkdev_disk->major = SIMP_BLKDEV_DEVICEMAJOR;
    simp_blkdev_disk->first_minor = 0;
    simp_blkdev_disk->fops = &simp_blkdev_fops;
    simp_blkdev_disk->queue = simp_blkdev_queue;
    set_capacity(simp_blkdev_disk,SIMP_BLKDEV_BYTES>>9);
    
    add_disk(simp_blkdev_disk);
    printk("module simp_blkdev added.\n");
    return 0;
 
error_alloc_queue:
    blk_cleanup_queue(simp_blkdev_queue);
 
error_alloc_disk:
    return ret;    
 
}
static void simp_blkdev_exit(void){
    del_gendisk(simp_blkdev_disk);
    put_disk(simp_blkdev_disk);
    blk_cleanup_queue(simp_blkdev_queue);
    printk("module simp_blkdev romoved.\n");
}
 
 
 
module_init(simp_blkdev_init);
module_exit(simp_blkdev_exit);
