#ifndef __METAL_H__
#define __METAL_H__

#include "material.h"

class Metal : public Material {
public:
	Metal(const RGBUnit & attenuation);
	Vec3 scatter(const Ray & r, const gObject * obj, const float t) const;
};

#endif