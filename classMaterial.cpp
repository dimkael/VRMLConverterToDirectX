#include "classMaterial.h"

Material::Material() {}

Material::Material(string _def) : Appearance(_def) {}

void Material::writeX(ofstream& file) {}

Material::~Material() {
	del(materials);
}