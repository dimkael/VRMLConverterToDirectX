#include "parseTransform.h"
#include "parseNode.h"
#include "define.h"


void parseTransform(ifstream& file, vector<Node*>* v, string def, string cur_file) {
	Transform* transform = new Transform(def);
	string str;

	do {
		file >> str;
		if (str == "scale") {
			for (int i = 0; i < 3; i++) {
				file >> transform->scale[i];
			}
		}
		if (str == "translation") {
			for (int i = 0; i < 3; i++) {
				file >> transform->translation[i];
			}
		}
		if (str == "rotation") {
			for (int i = 0; i < 4; i++) {
				file >> transform->rotation[i];
			}
		}
		else if (str == "children") {
			do {
				str = parseNode(file, transform->children, str, cur_file);
			} while (str != "]");
		}
	} while (str != "}" && str != "]");

	v->push_back(transform);

	if (transform->def != "") {
		DEF->insert(pair<string, Node*>(def, transform));
		def.clear();
	}
}