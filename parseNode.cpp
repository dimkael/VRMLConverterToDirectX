#include "parseNode.h"
#include "parseTransform.h"
#include "parseGroup.h"
#include "parseShape.h"
#include "parseInline.h"


string parseNode(ifstream& file, vector<Node*>* v, string str, string cur_file) {
	string def = "";

	do {
		file >> str;
		if (str == "DEF") {
			file >> def;
			def = def + "_" + cur_file;
		}
		else if (str == "Transform") {
			parseTransform(file, v, def, cur_file);
		}
		else if (str == "Group") {
			parseGroup(file, v, def, cur_file);
		}
		else if (str == "Shape") {
			parseShape(file, v, def, cur_file);
		}
		else if (str == "Inline") {
			parseInline(file, v);
		}
		else if (str == "") break;
	} while (str != "}" && str != "]");

	return str;
}