#ifndef _PIXEL_H
#define _PIXEL_H
#include <iostream>

class RGBUnit {
private:
  float r_, g_, b_;
public:
  RGBUnit(float r = 0, float g = 0, float b = 0): r_{r}, g_{g}, b_{b} {}
  friend std::ostream & operator << (std::ostream & out, const RGBUnit & pxl);
  inline float r() const {return r_;}
  inline float g() const {return g_;}
  inline float b() const {return b_;}

  void operator+=(const RGBUnit & p2);
  void operator/=(float c);
};

RGBUnit operator+(const RGBUnit & p1, const RGBUnit & p2);
RGBUnit operator/(const RGBUnit & p1, float c);
RGBUnit operator*(const RGBUnit & p1, const RGBUnit & p2);
RGBUnit operator*(const RGBUnit & p1, float c);
RGBUnit operator*(float c, const RGBUnit & p1);

#endif
