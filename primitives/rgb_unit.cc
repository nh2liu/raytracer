#include "rgb_unit.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, const RGBUnit &pxl) {
    float c = 255.99;
    out << uint32_t(pxl.r_ * c) << ' ' << uint32_t(pxl.g_ * c) << ' ' << uint32_t(pxl.b_ * c);
    return out;
}

RGBUnit operator+(const RGBUnit &p1, const RGBUnit &p2) {
    return RGBUnit(p1.r() + p2.r(), p1.g() + p2.g(), p1.b() + p2.b());
}

RGBUnit operator*(const RGBUnit &p1, const RGBUnit &p2) {
    return RGBUnit(p1.r() * p2.r(), p1.g() * p2.g(), p1.b() * p2.b());
}

RGBUnit operator/(const RGBUnit &p1, float c) {
    return RGBUnit(p1.r() / c, p1.g() / c, p1.b() / c);
}
RGBUnit operator*(const RGBUnit &p1, float c) {
    return RGBUnit(p1.r() * c, p1.g() * c, p1.b() * c);
}
RGBUnit operator*(float c, const RGBUnit &p1) {
    return RGBUnit(p1.r() * c, p1.g() * c, p1.b() * c);
}

void RGBUnit::operator+=(const RGBUnit &p2) {
    r_ += p2.r_;
    g_ += p2.g_;
    b_ += p2.b_;
}

void RGBUnit::operator/=(float c) {
    r_ /= c;
    g_ /= c;
    b_ /= c;
}
