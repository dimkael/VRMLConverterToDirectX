#include "parseGroup.h"
#include "parseNode.h"
#include "define.h"


void parseGroup(ifstream& file, vector<Node*>* v, string def, string cur_file) {
	Group* group = new Group(def);
	string str;

	do {
		file >> str;
		if (str == "children") {
			do {
				str = parseNode(file, group->children, str, cur_file);
			} while (str != "]");
		}

	} while (str != "}" && str != "]");
	
	v->push_back(group);

	if (group->def != "") {
		DEF->insert(pair<string, Node*>(def, group));
		def.clear();
	}
}