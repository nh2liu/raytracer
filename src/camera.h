#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <iostream>
#include <sstream>
#include "vec3.h"
#include "pixel.h"
#include "ray.h"

class gObject;

class Camera {
private:
  std::string name;
  int x_res, y_res;
  Vec3 lowerLeftCorner;
  Vec3 horizontal;
  Vec3 vertical;
  Vec3 origin;

  Pixel color(const Ray & r, std::vector <gObject * > & objects);
public:
  Camera(std::string name, int x, int y);
  std::string render(std::vector<gObject * > objects, int info_level = 1);
};

#endif
