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
    std::string name_;
    int x_res_, y_res_;
    Vec3 lower_left_corner_;
    Vec3 horizontal_;
    Vec3 vertical_;
    Vec3 origin_;
    int aliasing_its_;
    int max_bounces_;

    RGBUnit color(const Ray &r,
                  std::vector<std::shared_ptr<RenderObject>> &objects,
                  int bounces = 0);

  public:
    Camera(std::string name, int x, int y, int aliasing_level = 0,
           int max_bounces = 30);
    std::string render(std::vector<std::shared_ptr<RenderObject>> objects,
                       int info_level = 1, int gamma = 1);
};

#endif
