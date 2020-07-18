#include "vec3.h"
#include <cmath>
using namespace std;

Vec3::Vec3() {}

Vec3::Vec3(float x, float y, float z) : x0_{x}, x1_{y}, x2_{z} {}

float Vec3::mag() const { return sqrt(x0_ * x0_ + x1_ * x1_ + x2_ * x2_); }

Vec3 Vec3::unit() const { return (*this) / mag(); }

Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}
Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

Vec3 operator/(const Vec3 &v1, float c) {
    return Vec3(v1.x() / c, v1.y() / c, v1.z() / c);
}

Vec3 operator*(const Vec3 &v1, float c) {
    return Vec3(v1.x() * c, v1.y() * c, v1.z() * c);
}

Vec3 operator*(float c, const Vec3 &v1) {
    return Vec3(v1.x() * c, v1.y() * c, v1.z() * c);
}

bool operator==(const Vec3 &v1, const Vec3 &v2) {
    return v1.x() == v2.x() && v1.y() == v2.y() && v1.z() == v1.z();
}

float dot(const Vec3 &v1, const Vec3 &v2) {
    return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

std::ostream &operator<<(std::ostream &out, const Vec3 &v1) {
    out << v1.x() << ' ' << v1.y() << ' ' << v1.z();
    return out;
}
Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3((v1.y() * v2.z() - v1.z() * v2.y()),
                -(v1.x() * v2.z() - v1.z() * v2.x()),
                (v1.x() * v2.y() - v1.y() * v2.x()));
}
