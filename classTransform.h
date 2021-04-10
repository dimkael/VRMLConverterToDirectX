#pragma once

#include "classNode.h"


class Transform : public Node {
public:
	float scale[3];
	float translation[3];
	float rotation[4];
	vector<Node*>* children;

	Transform();

	Transform(string _def);

	void setTransformMatrix(float** matrix);

	void writeX(ofstream& file);

	~Transform();
};