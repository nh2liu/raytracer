#include "render_object.h"
RenderObject::~RenderObject() {}

Material * RenderObject::getMaterial() {
	return material;
}

void RenderObject::setMaterial(Material * m) {
	material = m;
}
