#ifndef _COLOR_H
#define _COLOR_H
#include <iostream>

class Pixel {
private:
  double r_, g_, b_;
public:
  Pixel(double r = 0, double g = 0, double b = 0): r_{r}, g_{g}, b_{b} {}
  friend std::ostream & operator << (std::ostream & out, const Pixel & pxl);
  inline double r() const {return r_;}
  inline double g() const {return g_;}
  inline double b() const {return b_;}

  void operator+=(const Pixel & p2);
  void operator/=(double c);
};

Pixel operator+(const Pixel & p1, const Pixel & p2);
Pixel operator/(const Pixel & p1, double c);
Pixel operator*(const Pixel & p1, double c);
Pixel operator*(double c, const Pixel & p1);

#endif
