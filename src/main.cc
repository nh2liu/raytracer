#include <iostream>
#include <fstream>
#include <vector>
#include "sphere.h"
#include "camera.h"
using namespace std;

int main(int argc, char ** argv) {
  // dimensions of the picture
  int x; int y;

  // file name
  string fileName;

  // path to place completed renders
  string path = "../renders/";
  if (argc > 1) {
    fileName = argv[1];
  } else {
    fileName = "rendered_img.ppm";
  }
  if (argc > 3) {
    x = atoi(argv[2]);
    y = atoi(argv[3]);
  } else {
      x = 200;
      y = 100;
  }
  
  Camera cam1("Front Camera", x, y, 3);

  // creating test objects
  vector<gObject * > objects;
  objects.push_back(new Sphere(Vec3(0, 0, -1), 0.5));
  objects.push_back(new Sphere(Vec3(0, -100.5, -1), 100));

  ofstream ofs;
  ofs.open((path + fileName).c_str());

  ofs << "P3" << endl << x << ' ' << y << endl << 255 << endl;
  ofs << cam1.render(objects, 1, 2);

  for (gObject * obj : objects) {
    delete obj;
  }

  ofs.close();
}
