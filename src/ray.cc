#include "ray.h"

Ray::Ray() {}
Ray::Ray(const Vec3 &a, const Vec3 &b) : p_vec{a}, d_vec{b} {}

Vec3 Ray::position() const { return p_vec; }

Vec3 Ray::direction() const { return d_vec; }

Vec3 Ray::positionAt(float t) const { return p_vec + t * d_vec; }
