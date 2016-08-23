// scene data structure
#ifndef _SCENE_H_
#define _SCENE_H_
#include "vec3.h"
#include <vector>

namespace yart {
	struct Camera {
		vec3 position;
		vec3 center; // center of interest, or view direction
		float angle; // view angle
		float aspect_ratio; // aspect ratio
		float hither, yon; // clipping distances
		float tilt; // tilt angle
		float xres, yres; // x and y resolution
	};

	/// let the center be at the origin, unit radius
	struct Sphere {
		// material property
		// 4x4 transform matrix
		yart::vec3 origin; 
		float radius;

		// material
		yart::vec3 rgb;
		std::string t_s;
		float kd;
		float ks;
		int n_i;
		float kr, gl, kt, f, tr;

		Sphere() : origin(0.0f), radius(1.0f) {}
	};

	struct Light {
		yart::vec3 position;
		float intensity;
		float falloff;
	};

	class Scene {
	private:
		yart::Camera camera;
		std::string file_name; // output file name
		std::vector<yart::Sphere> spheres;
		std::vector<yart::Light> lights;
		yart::vec3 background_color;
		float ambient;

	public:
		Scene();
		void parse_scene(std::string const & scene_path);

	};

}

#endif /*end of _SCENE_H_*/
