#pragma once

#include "classNode.h"

class Appearance : public Node {
public:
	string def;

	Appearance();

	Appearance(string _def);

	~Appearance();
};