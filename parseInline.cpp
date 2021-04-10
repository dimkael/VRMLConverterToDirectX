#include "parseInline.h"
#include "functions.h"
#include "define.h"


void parseInline(ifstream& file, vector<Node*>* v) {
	string str;

	do {
		file >> str;
		if (str == "url") {
			char chr;
			string name = "Data/";

			do {
				file >> chr;
				if (chr == '"') {
					file >> chr;
					do {
						name.push_back(chr);
						file >> chr;
					} while (chr != '"');
				}
			} while (chr != '}');
			str = chr;

			map<string, vector<Node*>*>::iterator it;
			it = FILES->find(name);

			if (it == FILES->cend()) {
				vector<Node*>* newVec = new vector<Node*>;

				parse(name, newVec);

				FILES->insert(pair<string, vector<Node*>*>(name, newVec));

				vector<Node*>::iterator itVec;
				for (itVec = newVec->begin(); itVec != newVec->end(); itVec++) {
					v->push_back(*itVec);
				}
			}
			else {
				vector<Node*>::iterator itVec;
				for (itVec = it->second->begin(); itVec != it->second->end(); itVec++) {
					v->push_back(*itVec);
				}
			}
		}
	} while (str != "}");
}