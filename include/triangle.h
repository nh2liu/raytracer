#include "g_object.h"
#include "vec3.h"
#include "ray.h"

class Triangle: public gObject {
private:
  Vec3 points[3];
  double radius;

  // norm of the equation, Ax + By + Cz = D
  Vec3 norm;
  double D;
public:
  Triangle();
  Triangle(const Vec3 p1, const Vec3 p2, const Vec3 p3);

  // inherits from g_object
  double intersect(const Ray & r, const double tMin, const double tMax) const;
  Vec3 normal(const Vec3 poi) const;
};
