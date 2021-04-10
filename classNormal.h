#pragma once

#include "classGeometry.h"


class Normal : public Geometry {
public:
	string def;
	vector<float*> vector;

	Normal();

	Normal(string _def);

	void writeX(ofstream& file);

	~Normal();
};