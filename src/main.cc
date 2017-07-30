#include <iostream>
#include <fstream>
#include <vector>
#include "vec3.h"
#include "pixel.h"
#include "ray.h"
#include "sphere.h"
using namespace std;

class gObject;

Pixel color(const Ray & r, vector <gObject * > & objects) {

  for (gObject * g : objects) {
    if (g->intersect(r, -1000, 1000)) {
      return Pixel(0.0, 1.0, 0.0);
    }
  }
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

  vector<gObject * > objects;
  Sphere * s1 = new Sphere(Vec3(0, 0, -1), 0.5);
  objects.push_back(s1);
  // code convention is written from top to bottom
  for (int j = y - 1; j >= 0; j--) {
    for (int i = 0; i < x; i++) {
      double u = double(i) / double(x);
      double d = double(j) / double(y);
      Ray r(origin, lowerLeftCorner + horizontal * u + vertical * d);
      Pixel pxl = color(r, objects);
      ofs << pxl;
    }
  }
  delete s1;
  ofs.close();
}
