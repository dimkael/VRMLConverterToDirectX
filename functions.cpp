#include "functions.h"
#include "parseNode.h"
#include <cmath>


void parse(string name, vector<Node*>* v) {
	ifstream file(name);
	string cur_file = name.substr(5);
	cur_file.resize(cur_file.size() - 4);
	string str;
	char chr;

	while (!file.eof()) {
		(void)parseNode(file, v, str, cur_file);
		file.get(chr);
	}

	file.close();
}

void createX(string name, vector<Node*>* v) {
	ofstream file(name);

	file << "xof 0302txt 0032\n";
	vector<Node*>::iterator it;
	for (it = v->begin(); it != v->end(); it++) {
		(*it)->writeX(file);
	}

	file.close();
}