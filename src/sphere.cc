#include "sphere.h"
#include "g_object.h"

Sphere::Sphere() : radius{0} {}

Sphere::Sphere(const Vec3 center, const double radius) :
center{center}, radius{radius} {}

double Sphere::intersect(const Ray & r, const double tMin, const double tMax) const {
  const Vec3 d = r.direction();
  const Vec3 p = r.position();
  const Vec3 p_c = p - center;
  const double a = dot(d, d);
  const double b = 2.0 * dot(d, p_c);
  const double c = dot(p_c, p_c) - radius * radius;
  const double discriminant = b * b - 4.0 * a * c;

  // smallest t
  double t = (- b - discriminant) / (2.0 * a);
  
  if (discriminant < 0 || t < tMin || t > tMax) {
    return -1;
  } else {
    return t;
  }
}
