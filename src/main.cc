#include <iostream>
#include <fstream>
#include "vec3.h"
#include "pixel.h"
#include "ray.h"
using namespace std;

Pixel color(const Ray & r) {
  Vec3 d_unit = r.direction().unit();
  double t = 0.5 * (d_unit.y() + 1.0);
  return (1.0-t) * Pixel(1.0, 1.0, 1.0) + t * Pixel(0.5, 0.7, 1.0);
}

int main(int argc, char ** argv) {
  int x = 800;
  int y = 600;
  string fileName;
  string path = "../renders/";
  if (argc > 1) {
    fileName = argv[1];
  } else {
    fileName = "rendered_img.ppm";
  }
  ofstream ofs;
  ofs.open((path + fileName).c_str());

  ofs << "P3" << endl << x << ' ' << y << endl << 255 << endl;
  Vec3 lowerLeftCorner(-2.0, -1.0, -1.0);
  Vec3 horizontal(4.0, 0.0, 0.0);
  Vec3 vertical(0, 2.0, 0.0);
  Vec3 origin(0.0, 0.0, 0.0);
  // code convention is written from top to bottom
  for (int j = y - 1; j >= 0; j--) {
    for (int i = 0; i < x; i++) {
      double u = double(i) / double(x);
      double d = double(j) / double(y);
      Ray r(origin, lowerLeftCorner + horizontal * u + vertical * d);
      Pixel pxl = color(r);
      ofs << pxl;
    }
  }

  ofs.close();
}
