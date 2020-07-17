#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

#include "camera.h"
#include "material.h"
#include "ray.h"
#include "render_object.h"
#include "rgb_unit.h"
#include "vec3.h"

using namespace std;

float randzeroone() { return rand() / (RAND_MAX + 1.); }

Camera::Camera(string name, int x_res, int y_res, int aliasing_level,
               int maxBounces)
    : name{name}, x_res{x_res}, y_res{y_res},
      lowerLeftCorner{Vec3(-2.0, -((2.0 * y_res) / x_res), -1.0)},
      horizontal{Vec3(4.0, 0.0, 0.0)}, vertical{Vec3(0, (4.0 * y_res) / x_res,
                                                     0.0)},
      origin{Vec3(0.0, 0.0, 0.0)}, aliasing_its{aliasing_level * 20},
      maxBounces{maxBounces} {}

RGBUnit Camera::color(const Ray &r, vector<RenderObject *> &objects,
                      int bounces) {
    float tMax = 1000;
    float tMin = 0.001;
    float lowestT = tMax;
    RenderObject *lowestObj = nullptr;
    for (RenderObject *obj : objects) {
        float t = obj->intersect(r, 0.0, tMax);
        if (t > tMin && t < lowestT) {
            lowestObj = obj;
            lowestT = t;
        }
    }
    // hit nothing or reaches maxBounces
    if (lowestObj == nullptr || bounces == maxBounces) {
        Vec3 d_unit = r.direction().unit();
        float t = 0.5 * (d_unit.y() + 1.0);
        return (1.0 - t) * RGBUnit(1.0, 1.0, 1.0) + t * RGBUnit(0.5, 0.7, 1.0);
        // Sphere Norms
        // hit something
    } else {
        // diffuse material at the moment
        Vec3 poi = r.positionAt(lowestT);
        Material *m = lowestObj->getMaterial();
        Vec3 newVec = m->scatter(r, lowestObj, lowestT);
        RGBUnit attenuation = m->getAttenuation();
        return attenuation * color(Ray(poi, newVec), objects, bounces++);
    }
}

RGBUnit gammaTransform(RGBUnit &p, int gamma) {
    float gammaInv = 1. / gamma;
    return RGBUnit(pow(p.r(), gammaInv), pow(p.g(), gammaInv),
                   pow(p.b(), gammaInv));
}

string Camera::render(vector<RenderObject *> objects, int info_level,
                      int gamma) {
    ostringstream oss;
    // code convention is written from top to bottom
    if (info_level == 1)
        cout << "Rendering " << name << endl;
    int progress_counter = 0;

    for (int j = y_res - 1; j >= 0; j--) {
        for (int i = 0; i < x_res; i++) {
            RGBUnit pxl = RGBUnit();
            // adding antialiasing
            for (int alias = 0; alias <= aliasing_its; ++alias) {
                float u = float(i + randzeroone()) / float(x_res);
                float d = float(j + randzeroone()) / float(y_res);
                Ray r(origin, lowerLeftCorner + horizontal * u + vertical * d);
                pxl += color(r, objects);
            }
            progress_counter++;
            // printing progress counter
            if (info_level == 1 &&
                progress_counter % ((x_res * y_res) / 10) == 0) {
                cout << progress_counter * 100 / (x_res * y_res) << "% done."
                     << endl;
            }
            pxl /= (aliasing_its + 1);
            oss << gammaTransform(pxl, gamma);
        }
    }
    return oss.str();
}
