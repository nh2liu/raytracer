#include <math.h>
#include "sphere.h"
#include "g_object.h"

Sphere::Sphere() : radius{0} {}

Sphere::Sphere(const Vec3 center, const float radius) :
center{center}, radius{radius} {}

float Sphere::intersect(const Ray & r, const float tMin, const float tMax) const {
  const Vec3 d = r.direction();
  const Vec3 p = r.position();
  const Vec3 p_c = p - center;

  // solving a*t^2 + b*t + c
  const float a = dot(d, d);
  const float b = 2.0 * dot(d, p_c);
  const float c = dot(p_c, p_c) - radius * radius;
  const float discriminant = b * b - 4.0 * a * c;

  // smallest t
  float t = (- b - sqrt(discriminant)) / (2.0 * a);
  
  if (discriminant < 0 || t < tMin || t > tMax) {
    return -1;
  } else {
    return t;
  }
}

Vec3 Sphere::normal(const Vec3 poi) const {
  return (poi - center).unit();
}
