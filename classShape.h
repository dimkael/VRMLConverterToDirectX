#pragma once

#include "classAppearance.h"
#include "classGeometry.h"


class Shape : public Node {
public:
	Appearance* appearance;
	Geometry* geometry;

	Shape();

	Shape(string _def);

	void writeX(ofstream& file);

	virtual ~Shape();
};