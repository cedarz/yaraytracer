#include <iostream>
#include "vec3.h"
#include "ppm.h"

int main() {
	yart::vec3 x(1.1f);
	std::cout << x << std::endl;

	yart::PPm ppm;
	ppm.readPpm("D:/zxs/ray-tracer/yart/yart/output.ppm");
	std::cout << ppm << std::endl;
	std::cin.get();
	return 0;
}