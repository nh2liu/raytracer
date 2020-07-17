#ifndef _PIXEL_H
#define _PIXEL_H
#include <iostream>

class Pixel {
private:
  float r_, g_, b_;
public:
  Pixel(float r = 0, float g = 0, float b = 0): r_{r}, g_{g}, b_{b} {}
  friend std::ostream & operator << (std::ostream & out, const Pixel & pxl);
  inline float r() const {return r_;}
  inline float g() const {return g_;}
  inline float b() const {return b_;}

  void operator+=(const Pixel & p2);
  void operator/=(float c);
};

Pixel operator+(const Pixel & p1, const Pixel & p2);
Pixel operator/(const Pixel & p1, float c);
Pixel operator*(const Pixel & p1, const Pixel & p2);
Pixel operator*(const Pixel & p1, float c);
Pixel operator*(float c, const Pixel & p1);

#endif
