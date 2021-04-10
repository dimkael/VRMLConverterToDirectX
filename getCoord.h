#pragma once

#include "classCoordinate.h"
#include "classNormal.h"
#include "classIndexedFaceSet.h"
#include "classIndexedLineSet.h"


string getCoord(ifstream& file, Coordinate* coord, string str);

string getNorm(ifstream& file, Normal* vector, string str);

string getCoordIndex(ifstream& file, IndexedFaceSet* coord, string str);

string getCoordIndex(ifstream& file, IndexedLineSet* coord, string str);

string getNormIndex(ifstream& file, IndexedFaceSet* coord, string str);