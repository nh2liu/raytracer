#include <iostream>
#include "pixel.h"
using namespace std;

ostream & operator << (ostream & out, const Pixel & pxl) {
  double c = 255.99;
  out << int(pxl.r_ * c) << ' ' << int(pxl.g_ * c) << ' ' << int(pxl.b_ * c) << endl;
  return out;
}

Pixel operator+(const Pixel & p1, const Pixel & p2) {
  return Pixel(p1.r() + p2.r(), p1.g() + p2.g(), p1.b() + p2.b());
}
Pixel operator/(const Pixel & p1, double c) {
  return Pixel(p1.r() / c, p1.g() / c, p1.b() / c);
}
Pixel operator*(const Pixel & p1, double c) {
  return Pixel(p1.r() * c, p1.g() * c, p1.b() * c);
}
Pixel operator*(double c, const Pixel & p1) {
  return Pixel(p1.r() * c, p1.g() * c, p1.b() * c);
}
