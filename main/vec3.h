#ifndef VEC3_H_
#define VEC3_H_
#include <iostream>
/*
Vec3 basic vector class for raytracing
*/

class Vec3 {
  private:
    float x0_, x1_, x2_;

  public:
    Vec3();
    Vec3(float x, float y, float z);

    inline float x() const { return x0_; }
    inline float y() const { return x1_; }
    inline float z() const { return x2_; }

    float mag() const; // returns magnitude of vector
    Vec3 unit() const; // returns unit vector
};

bool operator==(const Vec3 &v1, const Vec3 &v2);

Vec3 operator+(const Vec3 &v1, const Vec3 &v2);
Vec3 operator-(const Vec3 &v1, const Vec3 &v2);
Vec3 operator*(const Vec3 &v1, const Vec3 &v2);

Vec3 operator/(const Vec3 &v1, float c);
Vec3 operator*(const Vec3 &v1, float c);
Vec3 operator*(float c, const Vec3 &v1);

std::ostream &operator<<(std::ostream &out, const Vec3 &v1);

float dot(const Vec3 &v1, const Vec3 &v2);
Vec3 cross(const Vec3 &v1, const Vec3 &v2);

#endif
