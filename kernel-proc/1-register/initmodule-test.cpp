/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  模块测试程序 
 *
 *        Version:  1.0
 *        Created:  2020年03月30日 
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

int main(int argc, const char *argv[])
{
	std::cout << "Programe Version 1.0.0" << std::endl;	
	FILE* fp = NULL;
	if ( (fp = fopen("/dev/eddy0","a+")) == NULL ) {
		perror("open /dev/eddy0 fail");
		return EXIT_SUCCESS;
	}

	unsigned char databuf[5];
	int length = fread((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("length = %d\n",length);
		for ( int i=0;i<length;i++ ) {
			printf("databuf[i] = %x\n",databuf[i]);
		}
	}

	for ( int i=0;i<5;i++ ) {
		databuf[i] = databuf[i] + 0xA0;
	}
	length = fwrite((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("write length = %d\n",length);
	}

	//fseek(fp,0,SEEK_END);

	length = fread((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("length = %d\n",length);
		for ( int i=0;i<length;i++ ) {
			printf("databuf[i] = %x\n",databuf[i]);
		}
	}

	length = fread((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("length = %d\n",length);
		for ( int i=0;i<length;i++ ) {
			printf("databuf[i] = %x\n",databuf[i]);
		}
	}

	for ( int i=0;i<5;i++ ) {
		databuf[i] = databuf[i] + 0xB0;
	}
	length = fwrite((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("write length = %d\n",length);
	}

	length = fread((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("length = %d\n",length);
		for ( int i=0;i<length;i++ ) {
			printf("databuf[i] = %x\n",databuf[i]);
		}
	}

	length = fread((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("length = %d\n",length);
		for ( int i=0;i<length;i++ ) {
			printf("databuf[i] = %x\n",databuf[i]);
		}
	}



	fclose(fp);
	return EXIT_SUCCESS;
}
