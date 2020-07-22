#include "image_buffer.h"
#include <fstream>

#include <png++/png.hpp>
#include <png++/rgb_pixel.hpp>

using namespace std;

ImageBuffer::ImageBuffer(const uint32_t x_res, const uint32_t y_res)
    : x_res_{x_res}, y_res_{y_res}, buf_(x_res * y_res) {}

void ImageBuffer::setUnit(const RGBUnit &unit, const uint32_t x,
                          const uint32_t y) {
    buf_[y * x_res_ + x] = unit;
}

void ImageBuffer::ppm(const string file_path) const {
    ofstream ofs;
    ofs.open(file_path.c_str());

    ofs << "P3" << endl << x_res_ << ' ' << y_res_ << endl << 255 << endl;
    for (int32_t j = y_res_ - 1; j >= 0; j--) {
        for (int32_t i = 0; i < x_res_; i++) {
            ofs << buf_[j * x_res_ + i];
        }
    }
    ofs.close();
}

// Using external png++ library.
void ImageBuffer::png(const string file_path) const {
    png::image<png::rgb_pixel> png_image(x_res_, y_res_);
    for (int32_t j = 0; j < y_res_; j++) {
        for (int32_t i = 0; i < x_res_; i++) {
            RGBUnit u = buf_[j * x_res_ + i];
            png_image[y_res_ - j - 1][i] =
                png::rgb_pixel(u.r() * 255, u.g() * 255, u.b() * 255);
        }
    }
    png_image.write(file_path);
}