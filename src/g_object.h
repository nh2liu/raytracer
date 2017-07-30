#ifndef _gObject_h_
#define _gObject_h_
#include "ray.h"

class gObject {
public:
  virtual bool intersect(const Ray & r,
                         const double tMin,
                         const double tMax) const = 0;
};

#endif
