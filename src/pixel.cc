#include <iostream>
#include "pixel.h"
using namespace std;

ostream & operator << (ostream & out, const Pixel & pxl) {
  double c = 255.99;
  out << int(pxl.r * c) << ' ' << int(pxl.g * c) << ' ' << int(pxl.b * c) << endl;
  return out;
}
