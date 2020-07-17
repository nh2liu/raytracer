#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "g_object.h"
#include "pixel.h"

class Material {
private:
	Pixel attenuation;
public:
	Material(const Pixel & attenuation);
	virtual Vec3 scatter(const Ray & r, const gObject * obj, const float t) const = 0;
	Pixel getAttenuation();
};

#endif