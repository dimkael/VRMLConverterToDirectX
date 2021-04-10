#pragma once

#include "classGeometry.h"
#include "classCoordinate.h"
#include "classNormal.h"


class IndexedFaceSet : public Geometry {
public:
	string def;
	vector<vector<int>> coordIndex;
	vector<vector<int>> normalIndex;
	Coordinate* coord;
	Normal* normal;
	bool solid = true;
	bool normalPerVertex = true;

	IndexedFaceSet();

	IndexedFaceSet(string _def);

	void writeX(ofstream& file);

	~IndexedFaceSet();
};