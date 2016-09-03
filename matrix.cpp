#include "matrix.h"
#include <iostream>

namespace yart {
	template<T>
	Matrix::Identity;

	template<T>
	Matrix::Zero(static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0),
		static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0),
		static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0),
		static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
}


namespace yart{
	void fun() {
		std::cout << "namespace test" << std::endl;
	}
}