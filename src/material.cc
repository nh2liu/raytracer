#include "material.h"

Material::Material(const RGBUnit & attenuation) : attenuation{attenuation} {}


RGBUnit Material::getAttenuation() {
	return attenuation;
}