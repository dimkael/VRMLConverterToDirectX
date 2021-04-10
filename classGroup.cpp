#include "classGroup.h"


Group::Group() : children(new vector<Node*>) {}

Group::Group(string _def) : Node(_def), children(new vector<Node*>) {}

void Group::writeX(ofstream& file) {
	file << "Frame " << this->def << " {\n";
	vector<Node*>::iterator it;
	for (it = children->begin(); it != children->end(); it++) {
		(*it)->writeX(file);
	}
	file << "}\n";
}

Group::~Group() {
	delNodes(children);
}