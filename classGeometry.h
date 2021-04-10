#pragma once

#include "classNode.h"

class Geometry : public Node {
public:
	string def;

	Geometry();

	Geometry(string _def);

	~Geometry();
};