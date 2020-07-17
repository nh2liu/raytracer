#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "metal.h"
#include "lambertian.h"
#include "rgb_unit.h"
#include "sphere.h"
#include "camera.h"
#include "triangle.h"
using namespace std;

int main(int argc, char ** argv) {
  // dimensions of the picture, antialiasing level
  int x, y, aalias;

  // file name
  string fileName;

  // path to place completed renders
  string path = "../renders/";

  ifstream cameraConfig{"../camera.cfg"};
  cameraConfig >> fileName >> x >> y >> aalias;
  
  Camera cam1("Front Camera", x, y, aalias);
  cout << "Producing picture in file " << fileName << "." << endl;
  cout << "Dimensions " << x << " " << y << endl;
  cout << "Antialiasing level " << aalias << endl;
  
  // creating test objects
  vector<RenderObject * > objects;
  vector<Material * > materials;

  // reading in from landscape
  ifstream ifs{"../landscape.cfg"};
  string line;

  while (getline(ifs, line)) {
    istringstream iss{line};
    string type; string materialType;
    RenderObject * obj;
    Material * m;
    float r,g,b;
    iss >> type;
    if (type == "sphere") {
      float x, y, z, radius;
      iss >> x >> y >> z >> radius;
      obj = new Sphere(Vec3(x,y,z), radius);
    }

    iss >> materialType >> r >> g >> b;
    if (materialType == "lambertian") {
      m = new Lambertian(RGBUnit(r, g, b));
    } else if (materialType == "metal") {
      m = new Metal(RGBUnit(r, g, b));
    } else {
      throw 20;
    }

    obj->setMaterial(m);
    objects.push_back(obj);
    materials.push_back(m);
    cout << "Loaded a " << type << " with material " << materialType << endl;
  }

  // rendering landscape
  ofstream ofs;
  ofs.open((path + fileName).c_str());

  ofs << "P3" << endl << x << ' ' << y << endl << 255 << endl;
  ofs << cam1.render(objects, 1, 2);
  ofs.close();

  for (Material * m : materials) {
    delete m;
  }

  for (RenderObject * obj : objects) {
    delete obj;
  }

  
}
