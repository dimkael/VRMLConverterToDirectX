#pragma once

#include "classGeometry.h"


class Coordinate : public Geometry {
public:
	string def;
	vector<float*> points;

	Coordinate();

	Coordinate(string _def);

	void writeX(ofstream& file);

	~Coordinate();
};