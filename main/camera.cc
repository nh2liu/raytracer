#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <vector>

#include "camera.h"
#include "material.h"
#include "ray.h"
#include "render_object.h"
#include "rgb_unit.h"
#include "scene_manager.h"
#include "vec3.h"

using namespace std;

float randzeroone() { return rand() / (RAND_MAX + 1.); }

Camera::Camera(string name, int x_res, int y_res, int aliasing_level,
               int max_bounces)
    : name_{name}, x_res_{x_res}, y_res_{y_res},
      lower_left_corner_{Vec3(-2.0, -((2.0 * y_res) / x_res), -1.0)},
      horizontal_{Vec3(4.0, 0.0, 0.0)}, vertical_{Vec3(0, (4.0 * y_res) / x_res,
                                                       0.0)},
      origin_{Vec3(0.0, 0.0, 0.0)}, aliasing_its_{aliasing_level * 20},
      max_bounces_{max_bounces} {}

RGBUnit Camera::color(const Ray &r, vector<shared_ptr<RenderObject>> &objects,
                      int bounces) {
    float t_max = 1000;
    float t_min = 0.001;
    float t_lowest = t_max;
    shared_ptr<RenderObject> lowest_obj;
    for (auto obj : objects) {
        float t = obj->intersect(r, 0.0, t_max);
        if (t > t_min && t < t_lowest) {
            lowest_obj = obj;
            t_lowest = t;
        }
    }
    // hit nothing or reaches max_bounces
    if (!lowest_obj || bounces == max_bounces_) {
        Vec3 d_unit = r.direction().unit();
        float t = 0.5 * (d_unit.y() + 1.0);
        return (1.0 - t) * RGBUnit(1.0, 1.0, 1.0) + t * RGBUnit(0.5, 0.7, 1.0);
        // Sphere Norms
        // hit something
    } else {
        // diffuse material at the moment
        Vec3 poi = r.positionAt(t_lowest);
        auto m = lowest_obj->getMaterial().lock();
        if (m) {
            Vec3 newVec = m->scatter(r, lowest_obj, t_lowest);
            RGBUnit attenuation = m->getAttenuation();
            return attenuation * color(Ray(poi, newVec), objects, bounces++);
        } else {
            throw std::runtime_error("No material set for obj.");
        }
    }
}

RGBUnit gammaTransform(RGBUnit &p, int gamma) {
    float gamma_inv = 1. / gamma;
    return RGBUnit(pow(p.r(), gamma_inv), pow(p.g(), gamma_inv),
                   pow(p.b(), gamma_inv));
}

string Camera::render(const SceneManager &scene_manager, int info_level,
                      int gamma) {
    ostringstream oss;
    // code convention is written from top to bottom
    if (info_level == 1)
        cout << "Rendering " << name_ << endl;
    int progress_counter = 0;

    for (int j = y_res_ - 1; j >= 0; j--) {
        for (int i = 0; i < x_res_; i++) {
            RGBUnit pxl = RGBUnit();
            // adding antialiasing
            for (int alias = 0; alias <= aliasing_its_; ++alias) {
                float u = float(i + randzeroone()) / float(x_res_);
                float d = float(j + randzeroone()) / float(y_res_);
                Ray r(origin_,
                      lower_left_corner_ + horizontal_ * u + vertical_ * d);
                auto objects = scene_manager.getObjects(r);
                pxl += color(r, objects);
            }
            progress_counter++;
            // printing progress counter
            if (info_level == 1 &&
                progress_counter % ((x_res_ * y_res_) / 10) == 0) {
                cout << progress_counter * 100 / (x_res_ * y_res_) << "% done."
                     << endl;
            }
            pxl /= (aliasing_its_ + 1);
            oss << gammaTransform(pxl, gamma);
        }
    }
    return oss.str();
}