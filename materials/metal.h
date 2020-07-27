#ifndef METAL_H_
#define METAL_H_

#include "material.h"

class Metal : public Material {
  public:
    Metal(const RGBUnit &attenuation);
    Vec3 scatter(const Ray &r, const RenderObject *obj, const float t) const override;
};

#endif