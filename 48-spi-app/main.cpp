/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年07月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

#include <stdint.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

/* handle for spi */
int fd = 0;
static const char *device = "/dev/spidev1.1";
static uint32_t mode;
static uint8_t bits = 16;
static uint32_t speed = 100000;
static uint16_t delay = 10;

static uint8_t *tx;
static uint8_t *rx;
#define buffer_length 100

/* 错误信息显示 */
static void pabort(const char *s)
{
	perror(s);
	abort();
}

void init_spi_handle() {
	fd = open(device, O_RDWR);
	if (fd < 0)
		pabort("can't open device");

	tx = new uint8_t[buffer_length];
	rx = new uint8_t[buffer_length];
}

void set_parameters() {
	int ret = 0;

	
	/*三线制 */
	//mode |= SPI_3WIRE;

	/* 低字节在前 */
	mode |= SPI_LSB_FIRST;

	ret = ioctl(fd, SPI_IOC_WR_MODE32, &mode);
	if (ret == -1)
		pabort("can't set spi mode");

	ret = ioctl(fd, SPI_IOC_RD_MODE32, &mode);
	if (ret == -1)
		pabort("can't get spi mode");

	/*
	 * bits per word
	 */
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't set bits per word");

	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't get bits per word");

	/*
	 * max speed hz
	 */
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't set max speed hz");

	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't get max speed hz");
}

void release_spi_handle() {
	delete[] tx;
	delete[] rx;
	if ( fd > 0 )
		close(fd);
}

void send_data(uint16_t value) {
	int ret;
	struct spi_ioc_transfer tr;
	tr.tx_buf = (unsigned long)tx,
	tr.rx_buf = (unsigned long)rx,
	tr.len = 2;
	// 10ms delay
	tr.delay_usecs = delay;
	// 5000 Hz
	tr.speed_hz = speed;
	// 16bits a word
	tr.bits_per_word = bits;

	/*设置数据 */
	sprintf((char *)tx,"%2x",value);

	if (mode & SPI_TX_QUAD)
		tr.tx_nbits = 4;
	else if (mode & SPI_TX_DUAL)
		tr.tx_nbits = 2;

	if (mode & SPI_RX_QUAD)
		tr.rx_nbits = 4;
	else if (mode & SPI_RX_DUAL)
		tr.rx_nbits = 2;

	if (!(mode & SPI_LOOP)) {
		if (mode & (SPI_TX_QUAD | SPI_TX_DUAL))
			tr.rx_buf = 0;
		else if (mode & (SPI_RX_QUAD | SPI_RX_DUAL))
			tr.tx_buf = 0;
	}

	/* 发送发送数据 */
	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1)
		pabort("can't send spi message");
}

int main(int argc, const char *argv[]) {
	std::cout << "spi application test V1.0.0" << std::endl;	
	init_spi_handle();

	set_parameters();

	send_data(0x5A5A);
	send_data(0xA5A5);

	release_spi_handle();
	return EXIT_SUCCESS;
}
