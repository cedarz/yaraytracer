// linear algebra data structures and operations

#ifndef _MATH_H_
#define _MATH_H_

#include <cmath>
#include <ostream>

namespace yart {
	template<typename T>
	struct tvec3{
		typedef T value_type;
		typedef tvec3<T> type;

		union
		{
			struct
			{
				T x, y, z;
			};
			struct
			{
				T r, g, b;
			};
			//T data[3];
		};
		tvec3() {
			*this = tvec3(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
		}
		tvec3(T v) {
			*this = tvec3(v, v, v);
		}
		tvec3(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}


		type operator+= (type a) {
			*this = tvec3(this->x + a.x, this->y + a.y, this->z + a.z);
			return *this;
		}
		type operator-= (type a) {
			*this = tvec3(this->x - a.x, this->y - a.y, this->z - a.z);
			return *this;
		}

		value_type operator[](int index) {
			if (index == 0) return this->x;
			if (index == 1) return this->y;
			if (index == 2) return this->z;
		}

	};

	template<typename T>
	typename tvec3<T>::type operator+ (typename yart::tvec3<T>::type a, typename yart::tvec3<T>::type b) {
		return tvec3(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	template<typename T>
	typename tvec3<T>::type operator- (typename yart::tvec3<T>::type a, typename yart::tvec3<T>::type b) {
		return tvec3(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	template<typename T>
	std::ostream & operator<< (std::ostream & os, tvec3<T> v) {
		os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return os;
	}

	typedef tvec3<float> vec3;
}


#endif /*end of _MATH_H_*/