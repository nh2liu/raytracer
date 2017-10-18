#include <iostream>
#include <fstream>
#include <vector>
#include "metal.h"
#include "lambertian.h"
#include "pixel.h"
#include "sphere.h"
#include "camera.h"
#include "triangle.h"
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
  
  Camera cam1("Front Camera", x, y, 10);

  // creating test objects
  vector<gObject * > objects;
  vector<Material * > materials;
  //objects.push_back(new Triangle(Vec3(1,0,-2), Vec3(0.5,0.5,-2),Vec3(-1,0,-2)));
  gObject * sphere1 = new Sphere(Vec3(0, 0, -1), 0.5);
  gObject * sphere2 = new Sphere(Vec3(0, -100.5, -1), 100);

  Material * material1 = new Lambertian(Pixel(0.3,0.3,0.8));
  Material * material2 = new Metal(Pixel(0.5,0.5,0.5));

  sphere1->setMaterial(material1);
  sphere2->setMaterial(material2);
  
  objects.push_back(sphere1);
  objects.push_back(sphere2);
  materials.push_back(material1);
  materials.push_back(material2);

  ofstream ofs;
  ofs.open((path + fileName).c_str());

  ofs << "P3" << endl << x << ' ' << y << endl << 255 << endl;
  ofs << cam1.render(objects, 1, 2);
  ofs.close();

  for (Material * m : materials) {
    delete m;
  }

  for (gObject * obj : objects) {
    delete obj;
  }

  
}
