#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include "camera.h"
#include "g_object.h"
#include "vec3.h"
#include "pixel.h"
#include "ray.h"
using namespace std;

double randzeroone() {
  return rand() / (RAND_MAX + 1.);
}

Vec3 randomUnitSphereVec() {
  Vec3 rng;
  do {
    rng = 2.0 * Vec3(randzeroone(), randzeroone(), randzeroone()) - Vec3(1,1,1);
  } while (rng.mag() >= 1);
  return rng;
}

Camera::Camera(string name, int x_res, int y_res, int aliasing_level, int maxBounces) :
name{name},
x_res{x_res},
y_res{y_res},
lowerLeftCorner{Vec3 (-2.0, -((2.0 * y_res) / x_res), -1.0)},
horizontal{Vec3(4.0, 0.0, 0.0)},
vertical{Vec3(0, (4.0 * y_res) / x_res, 0.0)},
origin{Vec3(0.0, 0.0, 0.0)},
aliasing_its{aliasing_level * 20},
maxBounces{maxBounces} {}

Pixel Camera::color(const Ray & r, vector <gObject * > & objects, int bounces) {
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
  // hit nothing or reaches maxBounces
  if (lowestObj == nullptr || bounces == maxBounces) {
    Vec3 d_unit = r.direction().unit();
    double t = 0.5 * (d_unit.y() + 1.0);
    return (1.0-t) * Pixel(1.0, 1.0, 1.0) + t * Pixel(0.5, 0.7, 1.0);
    // Sphere Norms
    // hit something
  } else {
    // diffuse material at the moment
    Vec3 poi = r.positionAt(lowestT);
    Vec3 newVec = poi + lowestObj->normal(poi) + randomUnitSphereVec();
    return 0.5 * color(Ray(poi, newVec), objects, bounces++);
  }
}

string Camera::render(vector<gObject * > objects, int info_level) {
  ostringstream oss;
  // code convention is written from top to bottom
  if (info_level == 1) cout << "Rendering " << name << endl;
  int progress_counter = 0;

  for (int j = y_res - 1; j >= 0; j--) {
    for (int i = 0; i < x_res; i++) {
      Pixel pxl = Pixel();
      // adding antialiasing
      for (int alias = 0; alias <= aliasing_its; ++alias) {
        double u = double(i + randzeroone()) / double(x_res);
        double d = double(j + randzeroone()) / double(y_res);
        Ray r(origin, lowerLeftCorner + horizontal * u + vertical * d);
        pxl += color(r, objects);
      }
      progress_counter++;
      // printing progress counter
      if (info_level == 1 && progress_counter % ((x_res * y_res)/10) == 0) {
        cout << progress_counter * 100 / (x_res * y_res) << "% done." << endl;
      }
      pxl /= (aliasing_its + 1);
      oss << pxl;
    }
  }
  return oss.str();
}
