#include "metal.h"

using namespace std;

Metal::Metal(const RGBUnit &attenuation) : Material(attenuation) {}

Vec3 reflect(const Vec3 &v, const Vec3 &norm) {
    return v - 2 * dot(v, norm) * norm;
}

Vec3 Metal::scatter(RNGGenerator &rng_generator, const Ray &r,
                    const RenderObject *obj, const float t) const {
    Vec3 poi = r.positionAt(t);
    Vec3 new_vec = reflect(r.direction().unit(), obj->normal(poi));
    return new_vec;
}