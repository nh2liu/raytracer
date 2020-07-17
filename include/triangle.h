#include "render_object.h"
#include "vec3.h"
#include "ray.h"

class Triangle: public RenderObject {
private:
  Vec3 points[3];
  float radius;

  // norm of the equation, Ax + By + Cz = D
  Vec3 norm;
  float D;
public:
  Triangle();
  Triangle(const Vec3 p1, const Vec3 p2, const Vec3 p3);

  // inherits from render_object
  float intersect(const Ray & r, const float tMin, const float tMax) const;
  Vec3 normal(const Vec3 poi) const;
};
