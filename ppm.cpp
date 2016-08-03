#include <cassert>
#include "ppm.h"

namespace yart {
	bool PPm::readPpm(const std::string & xpath) {
		std::ifstream fin(xpath);
		if (!fin.is_open()) return false;
		std::string x;
		int tmp;
		fin >> x;
		if (x != "P3") {
			fin.close();
			return false;
		} 
		fin >> x; 
		std::getline(fin, x); //getline can't get throgh the newline char
		fin >> this->width >> this->height;
		fin >> this->maxval;
		assert(this->width > 0 && this->height > 0);
		this->data = new int[width * height * 3];
		int cnt = 0;
		assert(this->data);
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				fin >> data[cnt++];
				fin >> data[cnt++];
				fin >> data[cnt++];
			}
		}
		fin.close();
		if (cnt == width * height * 3) return true;
		else {
			delete data;
			return false;
		}
	}

	//write to a .ppm
	bool PPm::writePpm(const std::string & xpath) {
		std::ofstream fout(xpath);
		if (!fout.is_open()) {
			return false;
		}
		fout << "P3" << std::endl;
		fout << "# " << xpath << std::endl;
		fout << width << " " << height << std::endl;
		fout << maxval << std::endl;
		int cnt = 0;
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				fout << data[cnt++] << " " << data[cnt++] << " " << data[cnt++] << std::endl;
			}
		}
		return true;
	}

	std::ostream & operator<< (std::ostream & os, yart::PPm & ppm) {
		int cnt = 0;
		os << ppm.width << " " << ppm.height << std::endl;
		os << ppm.maxval << std::endl;
		for (int i = 0; i < ppm.height; ++i) {
			for (int j = 0; j < ppm.width; ++j) {
				os << ppm.data[cnt++] << " " << ppm.data[cnt++] << " " << ppm.data[cnt++] << std::endl;
			}
		}
		return os;
	}
}