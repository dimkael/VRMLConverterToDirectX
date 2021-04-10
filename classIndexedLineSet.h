#pragma once

#include "classGeometry.h"
#include "classCoordinate.h"


class IndexedLineSet : public Geometry {
public:
	string def;
	vector<int> coordIndex;
	Coordinate* coord;

	IndexedLineSet();

	IndexedLineSet(string _def);

	void writeX(ofstream& file);

	~IndexedLineSet();
};