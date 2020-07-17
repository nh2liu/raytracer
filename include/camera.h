#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <iostream>
#include <memory>
#include <sstream>

#include "ray.h"
#include "rgb_unit.h"
#include "vec3.h"

class RenderObject;

class Camera {
  private:
    std::string name;
    int x_res, y_res;
    Vec3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 origin;
    int aliasing_its;
    int maxBounces;

    RGBUnit color(const Ray &r,
                  std::vector<std::shared_ptr<RenderObject>> &objects,
                  int bounces = 0);

  public:
    Camera(std::string name, int x, int y, int aliasing_level = 0,
           int maxBounces = 30);
    std::string render(std::vector<std::shared_ptr<RenderObject>> objects,
                       int info_level = 1, int gamma = 1);
};

#endif
