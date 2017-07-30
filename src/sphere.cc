#include "sphere.h"
#include "math.h"
#include "g_object.h"

Sphere::Sphere() : radius{0} {}

Sphere::Sphere(const Vec3 center, const double radius) :
center{center}, radius{radius} {}

bool Sphere::intersect(const Ray & r, const double tMin, const double tMax) const {
  const Vec3 d = r.direction();
  const Vec3 p = r.position();
  const Vec3 p_c = p - center;

  double discriminant = pow(2.0 * dot(d, p_c),2) - 4.0 * dot(d, d) *
                        (dot(p_c, p_c) - radius * radius);

  return discriminant >= 0;
}
