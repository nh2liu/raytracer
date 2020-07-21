#ifndef CAMERA_H_
#define CAMERA_H_
#include <iostream>
#include <memory>

#include "image_buffer.h"
#include "primitives/ray.h"
#include "primitives/rgb_unit.h"
#include "primitives/vec3.h"

class SceneManager;
class RenderObject;

class Camera {
  private:
    std::string name_;
    uint32_t x_res_, y_res_;
    Vec3 lower_left_corner_;
    Vec3 horizontal_;
    Vec3 vertical_;
    Vec3 origin_;
    uint32_t aliasing_its_;
    uint32_t max_bounces_;

    RGBUnit color(const Ray &r,
                  std::vector<std::shared_ptr<RenderObject>> &objects,
                  uint32_t bounces = 0);

  public:
    Camera(std::string name, uint32_t x, uint32_t y, uint32_t aliasing_level = 0,
           uint32_t max_bounces = 30);
    ImageBuffer render(const SceneManager &scene_manager, uint32_t info_level = 1,
                       uint32_t gamma = 1);
};

#endif
