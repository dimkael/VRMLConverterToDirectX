#include "classNormal.h"


Normal::Normal() : def("") {}

Normal::Normal(string _def) : def(_def) {}

void Normal::writeX(ofstream& file) {}

Normal::~Normal() {
	del(vector);
}