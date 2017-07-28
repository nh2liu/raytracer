#include <iostream>
#include <fstream>
#include "vec3.h"
#include "pixel.h"
#include "ray.h"
using namespace std;



int main(int argc, char ** argv) {
  int x = 800;
  int y = 600;
  string fileName;
  string path = "../renders/";
  if (argc > 1) {
    fileName = argv[1];
  } else {
    fileName = "rendered_img.ppm";
  }
  ofstream ofs;
  ofs.open((path + fileName).c_str());

  ofs << "P3" << endl << x << ' ' << y << endl << 255 << endl;

  // code convention is written from top to bottom
  for (int j = y - 1; j >= 0; j--) {
    for (int i = 0; i < x; i++) {
      float r = float(i) / float(x);
      float g = float(j) / float(y);
      float b = 0.2;
      Pixel pxl(r, g, b);
      ofs << pxl;
    }
  }

  ofs.close();
}
