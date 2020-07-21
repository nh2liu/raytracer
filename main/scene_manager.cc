#include "scene_manager.h"
#include <iostream>
using namespace std;

shared_ptr<Sphere> SceneManager::createSphere(const Vec3 &center, float radius) {
    auto obj = make_shared<Sphere>(center, radius);
    objects_.push_back(obj);
    return obj;
}

shared_ptr<Triangle> SceneManager::createTriangle(const Vec3 &p1, const Vec3 &p2,
                                  const Vec3 &p3) {
    auto obj = make_shared<Triangle>(p1, p2, p3);
    objects_.push_back(obj);
    return obj;
}

vector<shared_ptr<RenderObject>> SceneManager::getObjects(const Ray &ray) const {
    return objects_;
}