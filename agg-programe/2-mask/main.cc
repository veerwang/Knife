/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  mask 可以将颜色给掩盖掉,留下本来的底色 
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

	unsigned char* buffer = new unsigned char[frame_width * frame_height * 3];

	// 0 为黑底  255 白底 背景底颜色
	memset(buffer, 120, frame_width * frame_height * 3);

	agg::rendering_buffer rbuf(buffer, 
			frame_width, 
			frame_height, 
			frame_width * 3);
	agg::pixfmt_rgb24 pixf(rbuf);


	unsigned char* mask_buffer = new unsigned char[frame_width * frame_height];
	agg::rendering_buffer mask_rbuf(mask_buffer, 
			frame_width, 
			frame_height, 
			frame_width);
	agg::amask_no_clip_gray8 amask(mask_rbuf);
 	agg::pixfmt_amask_adaptor<agg::pixfmt_rgb24, 
                              agg::amask_no_clip_gray8> pixf_amask(pixf, amask);

	// 间隔条纹
	for( int i = 0; i < frame_height; i=i+2 ) {
		unsigned val = 255 * i / frame_height;
		memset(mask_rbuf.row_ptr(i), val, frame_width);
	}

	agg::rgba8 span[frame_width];
	for( int i = 0; i < frame_width; ++i ) {
		agg::rgba c(380.0 + 400.0 * i / frame_width, 0.8);
		span[i] = agg::rgba8(c);
	}

	for( int i = 0; i < frame_height; ++i ) {
		pixf_amask.blend_color_hspan(0, i, frame_width, span, 0, 120);
	}

	write_ppm(buffer, frame_width, frame_height, "agg_test.ppm");

	delete [] buffer;
	buffer = NULL;

	return EXIT_SUCCESS;
}
