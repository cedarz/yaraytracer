#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <ostream>

namespace yart {
	template<typename T>
	struct Matrix {
		static Matrix Identity;
		static Matrix Zero;

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

		Matrix() {
			memset(m, 0, sizeof(m));
			x11 = static_cast<T>(1.0);
			x22 = static_cast<T>(1.0);
			x33 = static_cast<T>(1.0);
			x44 = static_cast<T>(1.0);
		}

		Matrix(T * _m) {
			assert(_m);
			if (_m) {
				memcpy(m, _m, 16 * sizeof(T));
			}
		}

		Matrix(T _x11, T _x12, T _x13, T _x14,
			T _x21, T _x22, T _x23, T _x24,
			T _x31, T _x32, T _x33, T _x34,
			T _x41, T _x42, T _x43, T _x44
		) : x11(_x11), x12(_x12), x13(_x13), x14(_x14),
			x21(_x21), x22(_x22), x23(_x23), x24(_x24),
			x31(_x31), x32(_x32), x33(_x33), x34(_x34),
			x41(_x41), x42(_x42), x43(_x43), x44(_x44) {}

		template<typename T>
		friend std::ostream & operator<< (std::ostream & os, yart::Matrix<T> const & mat);
	};

	
	void fun();
}

namespace yart {
	template <typename T>
	std::ostream & operator<< (std::ostream & os, yart::Matrix<T> const & mat) {
		//os << "hello, matrix";
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				os << mat.M[i][j] << " ";
			}
			os << std::endl;
		}
		return os;
	}

	template<typename T>
	Matrix<T> Matrix<T>::Identity;

	template<typename T>
	Matrix<T> Matrix<T>::Zero(static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0),
		static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0),
		static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0),
		static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0));
}

#endif