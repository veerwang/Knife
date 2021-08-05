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

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <agg_alpha_mask_u8.h>
#include <agg_basics.h>
#include <agg_pixfmt_amask_adaptor.h>
#include <agg_pixfmt_rgb.h>
#include <agg_rendering_buffer.h>

#include <agg_blur.h>
#include <agg_conv_contour.h>
#include <agg_conv_dash.h>
#include <agg_conv_marker.h>
#include <agg_conv_stroke.h>
#include <agg_ellipse.h>
#include <agg_gamma_lut.h>
#include <agg_path_storage.h>
#include <agg_rasterizer_scanline_aa.h>
#include <agg_renderer_markers.h>
#include <agg_renderer_primitives.h>
#include <agg_renderer_scanline.h>
#include <agg_rounded_rect.h>
#include <agg_scanline_p.h>
#include <agg_scanline_u.h>
#include <agg_span_allocator.h>
#include <agg_span_gradient.h>
#include <agg_span_interpolator_linear.h>
#include <agg_vcgen_markers_term.h>

#include <agg_gsv_text.h>

#include <agg_rendering_buffer.h>
#include <ctrl/agg_cbox_ctrl.h>
#include <ctrl/agg_slider_ctrl.h>

bool write_ppm(const unsigned char *buf, unsigned width, unsigned height,
               const char *file_name) {
        FILE *fd = fopen(file_name, "wb");
        if (fd) {
                fprintf(fd, "P6 %d %d 0xff ", width, height);
                fwrite(buf, 1, width * height * 3, fd);
                fclose(fd);
                return true;
        }
        return false;
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  draw_main_sharp
 *        Input:  left,right,up,down: 滑块边框的坐标 
 *        	  radium: 半径
 *       Output:
 *  Description:  绘制圆角矩形,同时也是滑块的主体
 * ============================================================================
 */
void draw_main_sharp(agg::rendering_buffer &rbuf, int left, int up, int right,
                     int down, int radium) {
        typedef agg::pixfmt_rgb24 pixfmt_type;
        typedef agg::renderer_base<agg::pixfmt_rgb24> renbase_type;
        typedef agg::renderer_scanline_aa_solid<renbase_type>
            render_scanline_type;

        agg::rgba8 color = agg::rgba8(0xff, 0xff, 0xff, 0xff);

        pixfmt_type pixf(rbuf);
        // 关键代码
        renbase_type rbase(pixf);
        // 关键代码
        render_scanline_type rens(rbase);

        // 关键代码
        agg::rasterizer_scanline_aa<> ras;
        // 关键代码
        agg::scanline_u8 sl;

        // 初始化一个矢量图形
        agg::rounded_rect r(left, up, right, down, radium);

        // 矢量图形，首先栅格化
        ras.add_path(r);
        // 渲染，也就是颜色的定义
        rens.color(color);
        // 真正进行渲染
        agg::render_scanlines(ras, sl, rens);
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  draw_mid_line
 *        Input:  left,up,right,down:整个滑块控件外框的坐标 
 *        	  xdis,中线偏离外框左边缘的距离
 *       Output:
 *  Description:  绘制中线   
 * ============================================================================
 */
void draw_mid_line(agg::rendering_buffer &rbuf, int left, int up, int right,
                   int down, int xdis ,agg::rgba8 color) {
        typedef agg::pixfmt_rgb24 pixfmt_type;
        typedef agg::renderer_base<agg::pixfmt_rgb24> renbase_type;
        typedef agg::renderer_scanline_aa_solid<renbase_type>
            render_scanline_type;

        int midlinex = left + xdis;
        int midliney = up + ((down - up) >> 1) + 1;

        pixfmt_type pixf(rbuf);
        // 关键代码
        renbase_type rbase(pixf);
        // 关键代码
        // 关键代码
        render_scanline_type rens(rbase);

        // 关键代码
        agg::rasterizer_scanline_aa<> ras;
        // 关键代码
        agg::scanline_u8 sl;

        // 画线
        agg::path_storage ps;
        ps.move_to(midlinex, midliney);
        ps.line_to(right - xdis, midliney);
        agg::conv_stroke<agg::path_storage, agg::vcgen_markers_term> csps(ps);
        csps.width(2);

        // 添加画线代码段
        ras.add_path(csps);

        // 渲染，也就是颜色的定义
        rens.color(color);
        // 真正进行渲染
        agg::render_scanlines(ras, sl, rens);
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  draw_circle
 *        Input:  up,down: 滑块外框的上下坐标
 *        	  radium: 滑块半径
 *        	  indicate: 滑块x坐标
 *        	  radium: 小滑块的半径 
 *       Output:
 *  Description:  绘制圆块   
 * ============================================================================
 */
void draw_circle(agg::rendering_buffer &rbuf, int up, int down, int indicate,
                 int radium, agg::rgba8 color, bool shadowflag) {
        typedef agg::pixfmt_rgb24 pixfmt_type;
        typedef agg::renderer_base<agg::pixfmt_rgb24> renbase_type;
        typedef agg::renderer_scanline_aa_solid<renbase_type>
            render_scanline_type;

        // 圆心位置
        int pointx = indicate;
        int pointy = up + ((down - up) >> 1);

        pixfmt_type pixf(rbuf);
        // 关键代码
        renbase_type rbase(pixf);
        // 关键代码
        // 关键代码
        render_scanline_type rens(rbase);

        // 关键代码
        agg::rasterizer_scanline_aa<> ras;
        // 关键代码
        agg::scanline_p8 sl;

        agg::ellipse e1;
        e1.init(pointx, pointy, radium, radium);

        ras.add_path(e1);
        rens.color(color);

        agg::render_scanlines(ras, sl, rens);

        if (shadowflag) {
                int shadow = 2;
                agg::rendering_buffer renBuffer;
                agg::recursive_blur<agg::rgba8, agg::recursive_blur_calc_rgba<>>
                    blur;
                pixfmt_type subpixfmt(renBuffer);
                subpixfmt.attach(
                    pixf, pointx - radium - shadow, pointy - radium - shadow,
                    pointx + radium + shadow, pointy + radium + shadow);
                blur.blur(subpixfmt, shadow);
        }
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  draw_slider
 *        Input:  left,up,right,down:滑块外框的坐标 
 *        	  radium: 滑块的半径
 *        	  nodepos: 滑块相对外框最左边的距离
 *       Output:
 *  Description:  绘制滑块功能 
 * ============================================================================
 */
void draw_slider(agg::rendering_buffer &rbuf, int left, int up, int right,
                 int down, int radium, int nodepos) {
	// 12 这个魔数是中条距离滑块外框的间距 
	// 8 这个数字是小滑块的半径
        draw_main_sharp(rbuf, left, up, right, down, radium);
        draw_mid_line(rbuf, left, up, right, down, 12,
                      agg::rgba8(0xA9, 0xA9, 0xA9, 0xff));
        draw_mid_line(rbuf, left + 12, up, left + nodepos, down, 0,
                      agg::rgba8(0x00, 0x00, 0xFF, 0xff));
        draw_circle(rbuf, up, down, left + nodepos, 8,
                    agg::rgba8(0x00, 0x00, 0x00, 0xFF), true);
        draw_circle(rbuf, up, down, left + nodepos, 8,
                    agg::rgba8(0xFF, 0xFF, 0xFF, 0xFF), false);
}

int main(int argc, const char *argv[]) {
        std::cout << "agg library program" << std::endl;

        int frame_width = 320;
        int frame_height = 480;

        typedef agg::pixfmt_rgb24 pixfmt_type;
        typedef agg::renderer_base<agg::pixfmt_rgb24> renbase_type;

        enum { bytes_per_pixel = 3 };

        unsigned char *buffer =
            new unsigned char[frame_width * frame_height * bytes_per_pixel];

        agg::rendering_buffer rbuf(buffer, frame_width, frame_height,
                                   frame_width * bytes_per_pixel);

        pixfmt_type pixf(rbuf);
        // 关键代码
        renbase_type rbase(pixf);
        // 关键代码

        // 背景颜色设置
        // agg::rgba c(380.0 + 400.0 , 0.8);
        // agg:rgba 每个分量的类型是double，并且从0~1.0
        agg::rgba c(0, 0, 0, 1.0);
        rbase.clear(c);
        // 背景颜色设置

        // 绘制图形
        draw_slider(rbuf, 50, 50, 280, 90, 10, 10);
        draw_slider(rbuf, 50, 50 + 50, 280, 90 + 50, 10, 280 - 50 + 1 - 10);
        draw_slider(rbuf, 50, 50 + 100, 280, 90 + 100, 10, 280 - 50 + 1 - 100);


	//显示到图片
        write_ppm(buffer, frame_width, frame_height, "agg_test.ppm");
        delete[] buffer;
        buffer = NULL;

        return EXIT_SUCCESS;
}
