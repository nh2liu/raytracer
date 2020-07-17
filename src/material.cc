#include "material.h"

Material::Material(const RGBUnit &attenuation) : attenuation_{attenuation} {}

RGBUnit Material::getAttenuation() { return attenuation_; }