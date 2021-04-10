#pragma once

#include "classNode.h"
#include "classShape.h"


class Group : public Node {
public:
	vector<Node*>* children;

	Group();

	Group(string _def);

	void writeX(ofstream& file);

	~Group();
};