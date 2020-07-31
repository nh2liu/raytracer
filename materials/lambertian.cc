#include "lambertian.h"

using namespace std;

Lambertian::Lambertian(const RGBUnit &attenuation) : Material(attenuation) {}

Vec3 randomUnitSphereVec(RNGGenerator &rng_generator) {
    Vec3 rng;
    do {
        rng = Vec3(rng_generator.uniform(-1, 1), rng_generator.uniform(-1, 1),
                   rng_generator.uniform(-1, 1));
    } while (rng.mag() >= 1);
    return rng;
}

Vec3 Lambertian::scatter(RNGGenerator &rng_generator, const Ray &r,
                         const RenderObject *obj, const float t) const {
    Vec3 poi = r.positionAt(t);
    Vec3 new_vec = poi + obj->normal(poi) + randomUnitSphereVec(rng_generator);
    return new_vec;
}