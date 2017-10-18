#include "g_object.h"
gObject::~gObject() {}

Material * gObject::getMaterial() {
	return material;
}

void gObject::setMaterial(Material * m) {
	material = m;
}
