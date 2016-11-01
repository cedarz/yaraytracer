#include <iostream>
#include "vec3.h"
#include "ppm.h"
#include "matrix.h"

int main() {
	yart::vec3 x(1.1f);
	std::cout << x << std::endl;

	yart::PPm ppm;
	ppm.read_ppm("D:/zxs/ray-tracer/yart/yart/output.ppm");
	std::cout << ppm << std::endl;
	yart::Matrix<float> mat;

	std::cout << yart::Matrix<float>::Identity << std::endl;

	yart::mat4 m = yart::Matrix<float>::Zero;
	std::cout << m << std::endl;
	yart::fun();

	std::cin.get();
	return 0;
}