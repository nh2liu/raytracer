#ifndef _VEC_3_H
#define _VEC_3_H

/*
Vec3 basic vector class for raytracing
*/

class Vec3 {
private:
  double x0, x1, x2;
public:
  Vec3();
  Vec3(double x, double y, double z);

  inline double x() const {return x0;}
  inline double y() const {return x1;}
  inline double z() const {return x2;}

  inline double mag(); // returns magnitude of vector
  inline Vec3 unit(); // returns unit vector

};

Vec3 operator+(const Vec3 & v1, const Vec3 & v2);
Vec3 operator*(const Vec3 & v1, const Vec3 & v2);

Vec3 operator/(const Vec3 & v1, double c);
Vec3 operator*(const Vec3 & v1, double c);
Vec3 operator*(double c, const Vec3 & v1);

double dot(const Vec3 & v1, const Vec3 & v2);
Vec3 cross(const Vec3 & v1, const Vec3 & v2);

#endif
