#include "matrix.h"
#include <iostream>

namespace yart {
	template <typename T>
	std::ostream & operator<< (std::ostream & os, yart::Matrix<T> const & mat) {
		os << "hello, matrix";
		return os;
	}
}

namespace yart{
	void fun() {
		std::cout << "namespace test" << std::endl;
	}
}