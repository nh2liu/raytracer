#include "metal.h"

Metal::Metal(const RGBUnit & attenuation) : Material(attenuation) {}

Vec3 reflect(const Vec3 & v, const Vec3 & norm) {
	return v - 2 * dot(v,norm) * norm;
}

Vec3 Metal::scatter(const Ray & r, const gObject * obj, const float t) const {
	Vec3 poi = r.positionAt(t);
    Vec3 newVec = reflect(r.direction().unit(), obj->normal(poi));
    return newVec;
}