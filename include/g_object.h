#ifndef _gObject_h_
#define _gObject_h_
#include "ray.h"
#include "vec3.h"
// main object class to detect hits
class gObject {
public:
  virtual ~gObject();

  // returns the intersection of the ray if hit
  // -1 otherwise
  virtual double intersect(const Ray & r,
                         const double tMin,
                         const double tMax) const = 0;

  // returns a normal vector to the hit (this vector is unit)
  // takes in the point of intersection between the ray and object
  virtual Vec3 normal(const Vec3 poi) const = 0;
};

#endif
