#include <boost/program_options.hpp>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <vector>

#include "camera.h"
#include "image_buffer.h"
#include "materials/lambertian.h"
#include "materials/metal.h"
#include "objects/sphere.h"
#include "objects/triangle.h"
#include "primitives/rgb_unit.h"
#include "scene_manager.h"


using namespace std;
namespace po = boost::program_options;

int32_t main(int32_t argc, char **argv) {
    string render_path;
    string camera_path;
    string scene_path;
    try {    
        po::options_description desc("Options");
        desc.add_options()
        ("render_path,r", po::value(&render_path), "Name of output ppm file.")
        ("camera_config,c", po::value(&camera_path), "Path to camera.cfg")
        ("scene_config,s", po::value(&scene_path), "Path to scene.cfg");
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch (exception &e) {
        cerr << e.what() << '\n';
        return 1;
    }

    // dimensions of the picture, antialiasing level
    uint32_t x, y, aalias;

    // file name
    string extension;
    string file_name;

    ifstream camera_config{camera_path};
    if (!camera_config.good()) {
        cerr << "Invalid camera configuration path." << '\n';
        return 2;
    }

    camera_config >> extension >> file_name >> x >> y >> aalias;
    if (!(extension == "ppm" || extension == "png")) {
        cerr << "Extension not supported." << '\n';
        return 3;
    }
    Camera cam1("Front Camera", x, y, aalias);
    cout << "Producing picture in file " << file_name << "." << extension << endl;
    cout << "Dimensions " << x << " " << y << endl;
    cout << "Antialiasing level " << aalias << endl;

    // creating test objects
    vector<shared_ptr<Material>> materials;

    // reading in from landscape
    ifstream ifs{scene_path};
    if (!ifs.good()) {
        cerr << "Invalid scene configuration path." << '\n';
        return 4;
    }

    string line;
    SceneManager scene_manager;
    
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
            obj = scene_manager.createSphere(Vec3(x, y, z), radius);
        } else if (type == "triangle") {
            Vec3 corners[3];
            float x, y, z;
            for (uint32_t i = 0; i < 3; i++) {
                iss >> x >> y >> z;
                cout << x << " " << y << " " << z << endl;
                corners[i] = Vec3(x, y, z);
            }
            obj = scene_manager.createTriangle(
                corners[0], corners[1], corners[2]
            );
        }

        iss >> material_type >> r >> g >> b;
        if (material_type == "lambertian") {
            m = make_shared<Lambertian>(RGBUnit(r, g, b));
        } else if (material_type == "metal") {
            m = make_shared<Metal>(RGBUnit(r, g, b));
        } else {
            throw 20;
        }
        obj->setMaterial(m.get());
        materials.push_back(m);
        cout << "Loaded a " << type << " with material " << material_type
             << endl;
    }

    // Benchmarking.
    auto start = chrono::steady_clock::now();

    // rendering landscape
    ImageBuffer img_buf = cam1.render(scene_manager, 1, 2);
    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout  << setprecision(2) << fixed;
    cout <<"Took " << (1. * elapsed.count()) / 1000 << " seconds.\n";

    // Saving to file.
    auto file_path = render_path + file_name + "." + extension;
    if (extension == "ppm") {
        img_buf.ppm(file_path);
    } else {
        img_buf.png(file_path);
    }
}
