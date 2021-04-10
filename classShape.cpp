#include "classShape.h"


Shape::Shape() : appearance(0), geometry(0) {}

Shape::Shape(string _def) : Node(_def), appearance(0), geometry(0) {}

void Shape::writeX(ofstream& file) {
	file << "Frame object {\n";
	geometry->writeX(file);
	file << "}\n";
}

Shape::~Shape() {
	if (def == "") {
		if (appearance != 0 && appearance->def == "")
			delete appearance;
		if (geometry != 0 && geometry->def == "")
			delete geometry;
	}
}