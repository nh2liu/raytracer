#include "render_object.h"

using namespace std;

RenderObject::~RenderObject() {}

weak_ptr<Material> RenderObject::getMaterial() { return material; }

void RenderObject::setMaterial(weak_ptr<Material> m) { material = m; }
