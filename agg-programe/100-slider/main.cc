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

#include <agg_basics.h>
#include <agg_rendering_buffer.h>
#include <agg_pixfmt_rgb.h>
#include <agg_pixfmt_amask_adaptor.h>
#include <agg_alpha_mask_u8.h>

#include <agg_rasterizer_scanline_aa.h>
#include <agg_scanline_p.h>
#include <agg_scanline_u.h>
#include <agg_renderer_scanline.h>
#include <agg_gamma_lut.h>
#include <agg_ellipse.h>
#include <agg_rounded_rect.h>
#include <agg_conv_stroke.h>
#include <agg_conv_dash.h>
#include <agg_conv_contour.h>
#include <agg_conv_marker.h>
#include <agg_path_storage.h>
#include <agg_vcgen_markers_term.h>
#include <agg_span_gradient.h>
#include <agg_span_allocator.h>
#include <agg_span_interpolator_linear.h>
#include <agg_blur.h>
#include <agg_renderer_primitives.h>
#include <agg_renderer_markers.h>

#include <agg_gsv_text.h> 

#include <ctrl/agg_slider_ctrl.h>
#include <ctrl/agg_cbox_ctrl.h>
#include <agg_rendering_buffer.h>

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

	int frame_width  = 640;
	int frame_height = 480;

	typedef agg::pixfmt_rgb24                     pixfmt_type;
	typedef agg::renderer_base<agg::pixfmt_rgb24> renbase_type;

	enum { bytes_per_pixel = 3 };

	unsigned char* buffer = new unsigned char[frame_width * 
		frame_height * 
		bytes_per_pixel];

	agg::rendering_buffer rbuf(buffer, 
			frame_width, 
			frame_height, 
			frame_width * bytes_per_pixel);

	pixfmt_type pixf(rbuf);
	// 关键代码
	renbase_type rbase(pixf);
	// 关键代码

	// 背景颜色设置
	agg::rgba c(380.0 + 400.0 , 0.8);
	rbase.clear(c);
	// 背景颜色设置


	/*
	void square(int x, int y, int r);
	void diamond(int x, int y, int r);
	void circle(int x, int y, int r);
	void crossed_circle(int x, int y, int r);
	void semiellipse_left(int x, int y, int r);
	void semiellipse_right(int x, int y, int r);
	void semiellipse_up(int x, int y, int r);
	void semiellipse_down(int x, int y, int r);
	void triangle_left(int x, int y, int r);
	void triangle_right(int x, int y, int r);
	void triangle_up(int x, int y, int r);
	void triangle_down(int x, int y, int r);
	void four_rays(int x, int y, int r);
	void cross(int x, int y, int r);
	void xing(int x, int y, int r);
	void dash(int x, int y, int r);
	void dot(int x, int y, int r);
	void pixel(int x, int y, int);
	*/

	write_ppm(buffer, frame_width, frame_height, "agg_test.ppm");
	delete [] buffer;
	buffer = NULL;

	return EXIT_SUCCESS;
}
