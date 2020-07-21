#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include <memory>
#include <vector>

#include "materials/material.h"
#include "objects/render_object.h"
#include "objects/sphere.h"
#include "objects/triangle.h"
#include "primitives/ray.h"

class SceneManager {
  private:
    std::vector<std::shared_ptr<RenderObject>> objects_;

  public:
    std::shared_ptr<Sphere> createSphere(const Vec3 &center, float radius);
    std::shared_ptr<Triangle> createTriangle(const Vec3 &p1, const Vec3 &p2,
                                             const Vec3 &p3);

    std::vector<std::shared_ptr<RenderObject>> getObjects(const Ray &ray) const;
};

#endif