#ifndef _RAY_H
#define _RAY_H
#include "vec3.h"

class Ray {
  private:
    Vec3 p_vec_;
    Vec3 d_vec_;

  public:
    Ray();
    Ray(const Vec3 &a, const Vec3 &b);

    Vec3 position() const;
    Vec3 direction() const;
    Vec3 positionAt(float t) const;
};

#endif
