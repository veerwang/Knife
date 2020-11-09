/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行agg库的实验代码
 *
 *        Version:  1.0
 *        Created:  2020年11月09日 
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

#include 	<agg_rendering_buffer.h>

bool write_ppm(const unsigned char* buf, 
               unsigned width, 
               unsigned height, 
               const char* file_name) {
    FILE* fd = fopen(file_name, "wb");
    if(fd) {
        fprintf(fd, "P6 %d %d 0xff ", width, height);
        fwrite(buf, 1, width * height * 3, fd);
        fclose(fd);
        return true;
    }
    return false;
}

int 
main(int argc, const char *argv[]) {
	std::cout << "agg library program" << std::endl;	

	int frame_width = 320;
	int frame_height = 240;

	unsigned char* buffer = new unsigned char[frame_width * frame_height * 3];

	memset(buffer, 255, frame_width * frame_height * 3);

	agg::rendering_buffer rbuf(buffer, 
			frame_width, 
			frame_height, 
			frame_width * 3);

	unsigned i;
	for(i = 0; i < rbuf.height()/2; ++i) {
		// Get the pointer to the beginning of the i-th row (Y-coordinate)
		// and shift it to the i-th position, that is, X-coordinate.
		//---------------
		unsigned char* ptr = rbuf.row_ptr(i) + i * 3;

		// PutPixel, very sophisticated, huh? :)
		//-------------
		*ptr++ = 127; // R
		*ptr++ = 200; // G
		*ptr++ = 98;  // B
	}

	write_ppm(buffer, frame_width, frame_height, "agg_test.ppm");

	delete [] buffer;
	buffer = NULL;

	return EXIT_SUCCESS;
}
