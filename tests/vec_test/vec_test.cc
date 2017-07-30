#include <iostream>
#include <assert.h>
#include <algorithm>
#include "../../src/vec3.h"
using namespace std;

int main() {
  Vec3 v1(1,2,3);
  Vec3 v2(4,5,6);
  assert(v1.x() == 1);
  assert(v1.y() == 2);
  assert(v1.z() == 3);
  assert(abs(v1.mag() - 3.741657) < 0.0001);
  assert(dot(v1,v2) == 32);
  assert(dot(v2,v1) == 32);
  cout << v2 - v1 - Vec3(3.0,3.0,3.0) << endl;
  assert(v1.unit().mag() - 1 < 0.001);
  cout << "All tests passed." << endl;
}
