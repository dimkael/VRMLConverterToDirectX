#include "functions.h"
#include "define.h"


int main() {
	{

		DEF = new map<string, Node*>;
		FILES = new map<string, vector<Node*>*>;

		string input = "model.wrl";
		string output = "model.x";
		vector<Node*>* nodes = new vector<Node*>;
		
		parse(input, nodes);
		createX(output, nodes);

		delNodes(nodes);
		del(DEF);
		del(FILES);
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}