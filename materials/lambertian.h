#ifndef LAMBERTIAN_H_
#define LAMBERTIAN_H_
#include "material.h"

class Lambertian : public Material {
  public:
    Lambertian(const RGBUnit &attenuation);
    Vec3 scatter(const Ray &r, const RenderObject *obj, const float t) const override;
};

#endif