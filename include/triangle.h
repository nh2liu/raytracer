#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "ray.h"
#include "render_object.h"
#include "vec3.h"

class Triangle : public RenderObject {
  private:
    Vec3 points_[3];
    float radius_;

    // norm of the equation, Ax + By + Cz = D
    Vec3 norm_;
    float D_;

  public:
    Triangle();
    Triangle(const Vec3 p1, const Vec3 p2, const Vec3 p3);

    // inherits from render_object
    float intersect(const Ray &r, const float t_min, const float t_max) const;
    Vec3 normal(const Vec3 poi) const;
};

#endif
