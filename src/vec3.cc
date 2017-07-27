#include <cmath>
#include "vec3.h"
using namespace std;

Vec3::Vec3(){}

Vec3::Vec3(double x, double y, double z) : x0{x}, x1{y}, x2{z} {}

inline double Vec3::mag() {
  return sqrt(x0 * x0 + x1 * x1 + x2 * x2);
}

inline Vec3 Vec3::unit() {
  return (*this) / mag();
}

inline Vec3 operator+(const Vec3 & v1, const Vec3 & v2) {
  return Vec3(v1.x() + v2.x(),
              v1.y() + v2.y(),
              v1.z() + v2.z());
}

inline Vec3 operator*(const Vec3 & v1, const Vec3 & v2) {
  return Vec3(v1.x() * v2.x(),
              v1.y() * v2.y(),
              v1.z() * v2.z());
}

template<class NUMBER> inline
Vec3 operator/(const Vec3 & v1, NUMBER c) {
  return Vec3(v1.x() / c,
              v1.y() / c,
              v1.z() / c);
}

template<class NUMBER> inline
Vec3 operator*(const Vec3 & v1, NUMBER c) {
  return Vec3(v1.x() * c,
              v1.y() * c,
              v1.z() * c);
}

template<class NUMBER> inline
Vec3 operator*(NUMBER c, const Vec3 & v1) {
  return Vec3(v1.x() * c,
              v1.y() * c,
              v1.z() * c);
}

inline double dot(const Vec3 & v1, const Vec3 & v2) {
  return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

inline Vec3 cross(const Vec3 & v1, const Vec3 & v2) {
  return Vec3( (v1.y() * v2.z() - v1.z() * v2.y()),
              -(v1.x() * v2.z() - v1.z() * v2.x()),
               (v1.x() * v2.y() - v1.y() * v2.x()));
}
