#include "classIndexedLineSet.h"

IndexedLineSet::IndexedLineSet() : def(""), coord(0) {}

IndexedLineSet::IndexedLineSet(string _def) : def(_def), coord(0) {}

void IndexedLineSet::writeX(ofstream& file) {}

IndexedLineSet::~IndexedLineSet() {
	delete coord;
}