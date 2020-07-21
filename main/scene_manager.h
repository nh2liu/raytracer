#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include <memory>
#include <vector>

#include "material.h"
#include "ray.h"
#include "render_object.h"
#include "sphere.h"
#include "triangle.h"

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