#include "triangle.h"

Triangle::Triangle() {}
Triangle::Triangle(const Vec3 p1, const Vec3 p2, const Vec3 p3)
    : points_{p1, p2, p3}, norm_{cross(p1 - p2, p1 - p3)}, D_{dot(norm_, p1)} {}

inline bool between01(float k) { return k >= 0 && k <= 1; }

float Triangle::intersect(const Ray &r, const float t_min,
                          const float t_max) const {
    // norm of the equation, Ax + By + Cz = D
    // dot(norm, poi) = D
    // dot(norm, p + td) = D
    // dot(norm, p) + tdot(norm, d) = D
    // t = (D - dot(norm, p)) / dot(norm, d)
    Vec3 p = r.position();
    Vec3 d = r.direction();

    float denom = dot(norm_, d);

    // Checking numerical stabililty.
    if (abs(denom) < 0.0001) {
        return -1;
    }

    float t = (D_ - dot(norm_, p)) / denom;

    if (t > t_min && t < t_max) {
        Vec3 poi = r.positionAt(t);
        float area = norm_.mag() / 2;
        float subarea1 =
            (cross(poi - points_[1], poi - points_[2]).mag()) / (2 * area);
        float subarea2 =
            (cross(poi - points_[2], poi - points_[0]).mag()) / (2 * area);
        float subarea3 =
            (cross(poi - points_[1], poi - points_[0]).mag()) / (2 * area);

        if (between01(subarea1) && between01(subarea2) && between01(subarea3)) {
            return t;
        }
    }
    return -1;
}

Vec3 Triangle::normal(const Vec3 poi) const { return norm_; }
