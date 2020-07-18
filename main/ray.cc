#include "ray.h"

Ray::Ray() {}
Ray::Ray(const Vec3 &a, const Vec3 &b) : p_vec_{a}, d_vec_{b} {}

Vec3 Ray::position() const { return p_vec_; }

Vec3 Ray::direction() const { return d_vec_; }

Vec3 Ray::positionAt(float t) const { return p_vec_ + t * d_vec_; }
