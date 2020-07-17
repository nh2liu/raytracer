#ifndef __SPHERE_H_
#define __SPHERE_H_
#include "render_object.h"
#include "vec3.h"

// a spherical 3 object
class Sphere : public RenderObject {
  private:
    Vec3 center;
    float radius;

  public:
    Sphere();
    Sphere(const Vec3 center, const float radius);

    // inherits from render_object
    float intersect(const Ray &r, const float tMin, const float tMax) const;
    Vec3 normal(const Vec3 poi) const;
};

#endif
