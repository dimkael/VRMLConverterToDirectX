#include "classCoordinate.h"


Coordinate::Coordinate() : def("") {}

Coordinate::Coordinate(string _def) : def(_def) {}

void Coordinate::writeX(ofstream& file) {
	file << " " << points.size() << ";\n";
	for (int i = 0; i != points.size(); i++) {
		for (int j = 0; j < 3; j++) {
			file << points[i][j] << ";";
		}
		if (i != points.size() - 1)
			file << ",\n";
		else
			file << ";\n";
	}
}

Coordinate::~Coordinate() {
	del(points);
}