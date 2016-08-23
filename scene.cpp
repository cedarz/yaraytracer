/// parse the scene file
#include "scene.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

yart::Scene::Scene() : ambient(0.0f) {
	spheres.clear();
	lights.clear();
}

void yart::Scene::parse_scene(std::string const & scene_path) {
	std::ifstream fin(scene_path);
	if (!fin.is_open()) {
		std::cerr << "Scene file can't be opened : " << scene_path << std::endl;
	}
	char line[256];
	while (!fin.eof()) {
		fin.getline(line, 256);
		if (line[0] == '#') continue;
		std::stringstream ss(line);
		std::string command;
		ss >> command;
		// sphere
		if (command == "sphere") {
			Sphere sph;
			ss >> sph.rgb.r >> sph.rgb.g >> sph.rgb.b;
			ss >> sph.t_s;
			ss >> sph.kd >> sph.ks;
			ss >> sph.n_i;
			ss >> sph.kr >> sph.gl >> sph.kt >> sph.f >> sph.tr;
			spheres.push_back(sph);
		}

		if (command == "camera") {
			ss >> camera.position.x >> camera.position.y >> camera.position.z;
			ss >> camera.center.x >> camera.center.y >> camera.center.z;
			ss >> camera.angle;
			ss >> camera.aspect_ratio;
			ss >> camera.hither >> camera.yon;
			ss >> camera.tilt;
			ss >> camera.xres >> camera.yres;
		}

		if (command == "light") {
			Light light;
			ss >> light.position.x >> light.position.y >> light.position.z;
			ss >> light.intensity;
			ss >> light.falloff;
			lights.push_back(light);
		}

		if (command == "ambient") {
			ss >> ambient;
		}

		if (command == "background") {
			ss >> background_color.r >> background_color.g >> background_color.b;
		}

		if (command == "output") {
			ss >> file_name;
		}


	}

}