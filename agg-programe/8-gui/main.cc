/*
 * =============================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  agg测试代码
 *
 *        Version:  1.0
 *        Created:  2021年08月04日
 *       Revision:  1
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang
 *   Organization:
 *
 * =============================================================================
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
 *         Name:  draw_slider
 *  Description:  绘制圆角矩形
 * ============================================================================
 */
void draw_slider(agg::rendering_buffer &rbuf, int left, int up, int right,
                 int down, int radium) {
        typedef agg::pixfmt_rgb24 pixfmt_type;
        typedef agg::renderer_base<agg::pixfmt_rgb24> renbase_type;
        typedef agg::renderer_scanline_aa_solid<renbase_type>
            render_scanline_type;

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
        agg::rounded_rect r1(left + 100, up + 100, right + 100, down + 100,
                             radium);

        // 进行缩放的核心代码
        agg::trans_affine polygon_mtx;
        polygon_mtx *= agg::trans_affine_scaling(1, 1);
        polygon_mtx *= agg::trans_affine_rotation(1.0 * agg::pi / 180.0);

        // conv_transform 核心函数，进行缩放
        agg::conv_transform<agg::rounded_rect> tr(r, polygon_mtx);
        // 矢量图形，首先栅格化
        ras.add_path(tr);
        ras.add_path(r1);
        // 渲染，也就是颜色的定义
        rens.color(agg::rgba8(0xff, 0xff, 0, 0xff));
        // 真正进行渲染
        agg::render_scanlines(ras, sl, rens);
}

int main(int argc, const char *argv[]) {
        std::cout << "agg library program" << std::endl;

        int frame_width = 640;
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
        draw_slider(rbuf, 50, 50, 250, 80, 10);

        write_ppm(buffer, frame_width, frame_height, "agg_test.ppm");
        delete[] buffer;
        buffer = NULL;

        return EXIT_SUCCESS;
}
