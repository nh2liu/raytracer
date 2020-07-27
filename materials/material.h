#ifndef MATERIAL_H_
#define MATERIAL_H_
#include <memory>

#include "objects/render_object.h"
#include "primitives/rgb_unit.h"

class Material {
  private:
    RGBUnit attenuation_;

  public:
    Material(const RGBUnit &attenuation);
    virtual Vec3 scatter(const Ray &r, const RenderObject *obj,
                         const float t) const = 0;
    RGBUnit getAttenuation();
};

#endif