#ifndef RENDEROBJECT_H_
#define RENDEROBJECT_H_
#include <memory>

#include "ray.h"
#include "vec3.h"

class Material;

// main object class to detect hits
class RenderObject {
  private:
    std::weak_ptr<Material> material_;

  public:
    virtual ~RenderObject();

    // returns the intersection of the ray if hit
    // -1 otherwise
    virtual float intersect(const Ray &r, const float t_min,
                            const float t_max) const = 0;

    // returns a normal vector to the hit (this vector is unit)
    // takes in the point of intersection between the ray and object
    virtual Vec3 normal(const Vec3 poi) const = 0;

    // getting and setting material
    std::weak_ptr<Material> getMaterial();
    void setMaterial(std::weak_ptr<Material> m);
};

#endif
