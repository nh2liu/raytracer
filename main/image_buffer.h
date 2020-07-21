#ifndef IMAGE_BUFFER_
#define IMAGE_BUFFER_
#include <iostream>
#include <memory>
#include <vector>

#include "primitives/rgb_unit.h"

class ImageBuffer {
  private:
    const uint32_t x_res_;
    const uint32_t y_res_;
    std::vector<RGBUnit> buf_;

  public:
    ImageBuffer(const uint32_t x_res, const uint32_t y_res);
    void setUnit(const RGBUnit &unit, const uint32_t x, const uint32_t y);

    void ppm(const std::string file_path) const;
};

#endif