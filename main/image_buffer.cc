#include "image_buffer.h"
#include <fstream>
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
    for (uint32_t j = y_res_ - 1; j >= 0; j--) {
        for (uint32_t i = 0; i < x_res_; i++) {
            ofs << buf_[j * x_res_ + i];
        }
    }
    ofs.close();
}