// scene data structure
#ifndef _SCENE_H_
#define _SCENE_H_
#include "vec3.h"

namespace yart {
	struct Camera {
		vec3 position;
		vec3 center; // center of interest, or view direction
		float angle; // view angle
		float aspect; // aspect ratio
		float hither, yon; // clipping distances
		float tilt; // tilt angle
		float xres, yres; // x and y resolution
	};

	/// let the center be at the origin, unit radius
	struct Sphere {
		// material properity
		// 4x4 transform matrix
		yart::vec3 origin; 
		float radius;
	};

	struct Light {
		yart::vec3 position;
		float intensity;
		float falloff;
	};


}

#endif /*endf of _SCENE_H_*/
