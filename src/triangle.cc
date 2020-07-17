#include "triangle.h"

Triangle::Triangle() {}
Triangle::Triangle(const Vec3 p1, const Vec3 p2, const Vec3 p3) {
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	norm = cross(p1 - p2, p1 - p3);
	D = dot(norm, p1);
}

bool between01(float k) {
	return k >= 0 && k <= 1;
}

float Triangle::intersect(const Ray & r, const float tMin, const float tMax) const {
  	// norm of the equation, Ax + By + Cz = D
  	// dot(norm, poi) = D
  	// dot(norm, p + td) = D
  	// dot(norm, p) + tdot(norm, d) = D
  	// t = (D - dot(norm, p)) / dot(norm, d)
  	Vec3 p = r.position();
	Vec3 d = r.direction();
	float t = (D - dot(norm, p)) / dot(norm, d);

	if (t > tMin && t < tMax) {
		Vec3 poi = r.positionAt(t);
		float area = norm.mag() / 2;
		float alpha = (cross(poi - points[1], poi - points[2]).mag()) / (2 * area);
		float beta = (cross(poi - points[2], poi - points[0]).mag()) / (2 * area);
		float gamma = 1 - alpha - beta;

		if (between01(alpha) && between01(beta) && between01(gamma)) {
			return t;
		}
	}
	return -1;
}

Vec3 Triangle::normal(const Vec3 poi) const {
	return norm;
}
