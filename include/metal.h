#ifndef __METAL_H__
#define __METAL_H__

#include "material.h"

class Metal : public Material {
public:
	Metal(const Pixel & attenuation);
	Vec3 scatter(const Ray & r, const gObject * obj, const double t) const;
};

#endif