#pragma once

#include "classAppearance.h"

class Material : public Appearance {
public:
	map<string, float*> materials;

	Material();

	Material(string _def);

	void writeX(ofstream& file);

	~Material();
};