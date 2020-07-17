#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "render_object.h"
#include "rgb_unit.h"

class Material {
  private:
    RGBUnit attenuation;

  public:
    Material(const RGBUnit &attenuation);
    virtual Vec3 scatter(const Ray &r, const RenderObject *obj,
                         const float t) const = 0;
    RGBUnit getAttenuation();
};

#endif