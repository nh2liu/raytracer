#ifndef _RenderObject_h_
#define _RenderObject_h_
#include "ray.h"
#include "vec3.h"

class Material;

// main object class to detect hits
class RenderObject {
  private:
    Material *material;

  public:
    virtual ~RenderObject();

    // returns the intersection of the ray if hit
    // -1 otherwise
    virtual float intersect(const Ray &r, const float tMin,
                            const float tMax) const = 0;

    // returns a normal vector to the hit (this vector is unit)
    // takes in the point of intersection between the ray and object
    virtual Vec3 normal(const Vec3 poi) const = 0;

    // getting and setting material
    Material *getMaterial();
    void setMaterial(Material *m);
};

#endif
