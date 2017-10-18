#include "material.h"

Material::Material(const Pixel & attenuation) : attenuation{attenuation} {}


Pixel Material::getAttenuation() {
	return attenuation;
}