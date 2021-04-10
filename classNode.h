#pragma once

#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

#include <string>
#include <fstream>
#include "del.h"
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::pair;


class Node {
public:
	string def;

	Node();

	Node(string _def);

	virtual void writeX(ofstream& file) = 0;

	virtual ~Node();
};