#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include "camera.h"
#include "lambertian.h"
#include "metal.h"
#include "rgb_unit.h"
#include "sphere.h"
#include "triangle.h"
using namespace std;

int main(int argc, char **argv) {
    // dimensions of the picture, antialiasing level
    int x, y, aalias;

    // file name
    string file_name;

    // path to place completed renders
    string path = "renders/";

    ifstream camera_config{"camera.cfg"};
    camera_config >> file_name >> x >> y >> aalias;

    Camera cam1("Front Camera", x, y, aalias);
    cout << "Producing picture in file " << file_name << "." << endl;
    cout << "Dimensions " << x << " " << y << endl;
    cout << "Antialiasing level " << aalias << endl;

    // creating test objects
    vector<shared_ptr<RenderObject>> objects;
    vector<shared_ptr<Material>> materials;

    // reading in from landscape
    ifstream ifs{"landscape.cfg"};
    string line;

    while (getline(ifs, line)) {
        istringstream iss{line};
        string type;
        string material_type;
        shared_ptr<RenderObject> obj;
        shared_ptr<Material> m;
        float r, g, b;
        iss >> type;
        if (type == "sphere") {
            float x, y, z, radius;
            iss >> x >> y >> z >> radius;
            obj = make_shared<Sphere>(Vec3(x, y, z), radius);
        }

        iss >> material_type >> r >> g >> b;
        if (material_type == "lambertian") {
            m = make_shared<Lambertian>(RGBUnit(r, g, b));
        } else if (material_type == "metal") {
            m = make_shared<Metal>(RGBUnit(r, g, b));
        } else {
            throw 20;
        }

        obj->setMaterial(m);
        objects.push_back(obj);
        materials.push_back(m);
        cout << "Loaded a " << type << " with material " << material_type
             << endl;
    }

    // rendering landscape
    ofstream ofs;
    ofs.open((path + file_name).c_str());

    ofs << "P3" << endl << x << ' ' << y << endl << 255 << endl;
    ofs << cam1.render(objects, 1, 2);
    ofs.close();
}
