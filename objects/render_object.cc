#include "render_object.h"

using namespace std;

RenderObject::~RenderObject() {}

Material *RenderObject::getMaterial() { return material_; }

void RenderObject::setMaterial(Material *m) { material_ = m; }
