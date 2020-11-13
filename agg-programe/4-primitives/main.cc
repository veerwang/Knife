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
	agg::rgba c(380.0 + 400.0 * 0 / frame_width, 0.8);
	rbase.clear(c);
	// 背景颜色设置

	// render_primitives 绘制基本元素点、线、矩形等的类
	agg::renderer_primitives<renbase_type> rp(rbase);
	agg::rgba fc(380.0 + 400.0 * 1 / 3, 0.8);
	rp.fill_color(fc);

	agg::rgba lc(380.0 + 400.0 * 2 / 3, 0.8);
	rp.line_color(lc);

	// 绘制元素
	// 空心矩形
	rp.rectangle(100,200,200,300);
	// 实心矩形
	rp.solid_rectangle(300,200,400,300);
	// 边界矩形
	rp.outlined_rectangle(500,200,600,300);
	// render_primitives 绘制基本元素点、线、矩形等的类
	// ellipse 类似
	rp.ellipse(100,100,80,40);	
	// 注意，这边画线的坐标采用的是subpixel方式,需要放到256倍
	rp.line(0<<8,0<<8,frame_width<<8,frame_height<<8);

	agg::rgba nlc(380.0 + 400.0 * 2 / 4, 0.8);
	rp.line_color(nlc);

	rp.move_to(100<<8,400<<8);
	rp.line_to(200<<8,420<<8,false);
	rp.line_to(250<<8,420<<8,true);

	write_ppm(buffer, frame_width, frame_height, "agg_test.ppm");
	delete [] buffer;
	buffer = NULL;

	return EXIT_SUCCESS;
}
