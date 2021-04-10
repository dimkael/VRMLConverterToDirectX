#include "classIndexedFaceSet.h"

IndexedFaceSet::IndexedFaceSet() : def(""), coord(0), normal(0) {}

IndexedFaceSet::IndexedFaceSet(string _def) : def(_def), coord(0), normal(0) {}

void IndexedFaceSet::writeX(ofstream& file) {
	file << "Mesh object {\n";

	coord->writeX(file);
	file << "\n";

	file << " " << coordIndex.size() << ";\n";
	for (int i = 0; i != coordIndex.size(); i++) {
		file << coordIndex[i].size() << "; ";
		for (int j = 0; j != coordIndex[i].size(); j++) {
			file << coordIndex[i][j];
			if (j != coordIndex[i].size() - 1)
				file << ",";
			else
				file << ";";
		}
		if (i != coordIndex.size() - 1)
			file << ",\n";
		else
			file << ";\n";
	}



	file << "}\n";
}

IndexedFaceSet::~IndexedFaceSet() {
	if (coord != 0 && coord->def == "") {
		delete coord;
	}
	if (normal != 0 && normal->def == "") {
		delete normal;
	}
}