#ifndef _PPM_H_
#define _PPM_H_
#include <string>
#include <fstream>

namespace yart{
	class PPm {
	private:
		int maxval;
		int width, height;
		std::string path;
		int *data;
	public:
		PPm() : data(NULL) {}
		PPm(std::string & p, int mv, int w, int h) : path(p), maxval(mv),
			width(w), height(h), data(NULL) {}
		bool read_ppm(const std::string & xpath);
		bool write_ppm(const std::string & xpath);

		~PPm() {
			if (data) delete data;
		}

		friend std::ostream & operator<< (std::ostream & os, yart::PPm & ppm);
	};

	
	
}

#endif /*_PPM_H_*/