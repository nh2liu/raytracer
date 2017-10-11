#ifndef __SPHERE_H_
#define __SPHERE_H_
#include "vec3.h"
#include "g_object.h"

// a spherical 3 object
class Sphere: public gObject {
private:
  Vec3 center;
  double radius;
public:
  Sphere();
  Sphere(const Vec3 center, const double radius);

  // inherits from g_object
  double intersect(const Ray & r, const double tMin, const double tMax) const;
  Vec3 normal(const Vec3 poi) const;
};

#endif
