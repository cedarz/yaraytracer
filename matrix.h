#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <ostream>

namespace yart {
	template<typename T>
	struct Matrix {
		union {
			T m[16];
			T M[4][4];
			struct
			{
				T	x11, x12, x13, x14,
					x21, x22, x23, x24,
					x31, x32, x33, x34,
					x41, x42, x43, x44;
			};
		};
		
		template<typename T>
		friend std::ostream & operator<< (std::ostream & os, yart::Matrix<T> const & mat);
	};

	void fun();
}

#endif