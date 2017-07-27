#ifndef _COLOR_H
#define _COLOR_H
#include <iostream>

class Pixel {
private:
  double r, g, b;
public:
  Pixel(double r = 0, double g = 0, double b = 0):
   r{r}, g{g}, b{b} {}
  friend std::ostream & operator << (std::ostream & out, const Pixel & pxl);
};

#endif
