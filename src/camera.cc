#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <random>
#include "camera.h"
#include "g_object.h"
#include "vec3.h"
#include "pixel.h"
#include "ray.h"
using namespace std;

Camera::Camera(string name, int x_res, int y_res, int aliasing_level) :
name{name},
x_res{x_res},
y_res{y_res},
lowerLeftCorner{Vec3 (-2.0, -((2.0 * y_res) / x_res), -1.0)},
horizontal{Vec3(4.0, 0.0, 0.0)},
vertical{Vec3(0, (4.0 * y_res) / x_res, 0.0)},
origin{Vec3(0.0, 0.0, 0.0)},
aliasing_its{aliasing_level * 20} {}

Pixel Camera::color(const Ray & r, vector <gObject * > & objects) {
  double tMax = 1000;
  double lowestT = tMax;
  gObject * lowestObj = nullptr;
  for (gObject * obj : objects) {
    double t = obj->intersect(r, 0.0, tMax);
    if (t > -1 && t < lowestT) {
      lowestObj = obj;
      lowestT = t;
    }
  }
  // hit something
  if (lowestObj == nullptr) {
    Vec3 d_unit = r.direction().unit();
    double t = 0.5 * (d_unit.y() + 1.0);
    return (1.0-t) * Pixel(1.0, 1.0, 1.0) + t * Pixel(0.5, 0.7, 1.0);
    // Sphere Norms
  } else {
    Vec3 N = (r.positionAt(lowestT) - Vec3(0,0,-1)).unit();
    return 0.5 * Pixel(N.x() + 1, N.y() + 1, N.z() + 1);
  }
}

double randzeroone() {
  return rand() / (RAND_MAX + 1.);
}

string Camera::render(vector<gObject * > objects, int info_level) {
  ostringstream oss;
  // code convention is written from top to bottom
  if (info_level == 1) cout << "Rendering " << name << endl;

  for (int j = y_res - 1; j >= 0; j--) {
    for (int i = 0; i < x_res; i++) {
      Pixel pxl = Pixel();
      for (int alias = 0; alias <= aliasing_its; ++alias) {
        double u = double(i + randzeroone()) / double(x_res);
        double d = double(j + randzeroone()) / double(y_res);
        Ray r(origin, lowerLeftCorner + horizontal * u + vertical * d);
        pxl += color(r, objects);
      }
      pxl /= (aliasing_its + 1);
      oss << pxl;
    }
  }
  return oss.str();
}
