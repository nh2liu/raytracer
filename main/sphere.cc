#include "sphere.h"
#include "render_object.h"
#include <math.h>

Sphere::Sphere() : radius_{0} {}

Sphere::Sphere(const Vec3 center, const float radius)
    : center_{center}, radius_{radius} {}

float Sphere::intersect(const Ray &r, const float t_min,
                        const float t_max) const {
    const Vec3 d = r.direction();
    const Vec3 p = r.position();
    const Vec3 p_c = p - center_;

    // solving a*t^2 + b*t + c
    const float a = dot(d, d);
    const float b = 2.0 * dot(d, p_c);
    const float c = dot(p_c, p_c) - radius_ * radius_;
    const float discriminant = b * b - 4.0 * a * c;

    // smallest t
    float t = (-b - sqrt(discriminant)) / (2.0 * a);

    if (discriminant < 0 || t < t_min || t > t_max) {
        return -1;
    } else {
        return t;
    }
}

Vec3 Sphere::normal(const Vec3 poi) const { return (poi - center_).unit(); }
