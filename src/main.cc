#include <iostream>
#include <fstream>
#include <vector>
#include "sphere.h"
#include "camera.h"
using namespace std;

int main(int argc, char ** argv) {
  string fileName;
  string path = "../renders/";
  if (argc > 1) {
    fileName = argv[1];
  } else {
    fileName = "rendered_img.ppm";
  }

  int x, y;
  cin >> x >> y;
  Camera cam1("Front Camera", x, y);

  vector<gObject * > objects;
  Sphere * s1 = new Sphere(Vec3(0, 0, -1), 0.5);
  objects.push_back(s1);

  ofstream ofs;
  ofs.open((path + fileName).c_str());

  ofs << "P3" << endl << x << ' ' << y << endl << 255 << endl;
  ofs << cam1.render(objects);

  for (gObject * obj : objects) {
    delete obj;
  }

  ofs.close();
}
