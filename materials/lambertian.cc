#include "lambertian.h"

using namespace std;

Lambertian::Lambertian(const RGBUnit &attenuation) : Material(attenuation) {}

float static randzeroone() { return rand() / (RAND_MAX + 1.); }

Vec3 randomUnitSphereVec() {
    Vec3 rng;
    do {
        rng = 2.0 * Vec3(randzeroone(), randzeroone(), randzeroone()) -
              Vec3(1, 1, 1);
    } while (rng.mag() >= 1);
    return rng;
}

Vec3 Lambertian::scatter(const Ray &r, const shared_ptr<RenderObject> obj,
                         const float t) const {
    Vec3 poi = r.positionAt(t);
    Vec3 new_vec = poi + obj->normal(poi) + randomUnitSphereVec();
    return new_vec;
}