#include <vector>
#include <iostream>
#include <sstream>
#include "camera.h"
#include "g_object.h"
#include "vec3.h"
#include "pixel.h"
#include "ray.h"
using namespace std;

Camera::Camera(string name, int x_res, int y_res) :
name{name},
x_res{x_res},
y_res{y_res},
lowerLeftCorner{Vec3 (-2.0, -((2.0 * y_res) / x_res), -1.0)},
horizontal{Vec3(4.0, 0.0, 0.0)},
vertical{Vec3(0, (4.0 * y_res) / x_res, 0.0)},
origin{Vec3(0.0, 0.0, 0.0)} {}

Pixel Camera::color(const Ray & r, vector <gObject * > & objects) {
  for (gObject * g : objects) {
    if (g->intersect(r, -1000, 1000)) {
      return Pixel(0.0, 1.0, 0.0);
    }
  }
  Vec3 d_unit = r.direction().unit();
  double t = 0.5 * (d_unit.y() + 1.0);
  return (1.0-t) * Pixel(1.0, 1.0, 1.0) + t * Pixel(0.5, 0.7, 1.0);
}

string Camera::render(vector<gObject * > objects, int info_level) {
  ostringstream oss;
  // code convention is written from top to bottom
  if (info_level == 1) cout << "Rendering " << name << endl;

  for (int j = y_res - 1; j >= 0; j--) {
    for (int i = 0; i < x_res; i++) {
      double u = double(i) / double(x_res);
      double d = double(j) / double(y_res);
      Ray r(origin, lowerLeftCorner + horizontal * u + vertical * d);
      Pixel pxl = color(r, objects);
      oss << pxl;
    }
  }
  return oss.str();
}
