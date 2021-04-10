#include "getCoord.h"


string getCoord(ifstream& file, Coordinate* coord, string str) {
	float* val;
	float buf;
	char chr;

	do {
		file >> str;
		if (str == "[" || str == ",") {
			file >> chr;
			if (chr == ']') break;
			file.putback(chr);
			val = new float[3];
			for (int i = 0; i < 3; i++) {
				file >> buf;
				val[i] = buf;
			}
			coord->points.push_back(val);
		}
	} while (str != "]");

	return str;
}


string getNorm(ifstream& file, Normal* vector, string str) {
	float* val;
	float buf;
	char chr;

	do {
		file >> str;
		if (str == "[" || str == ",") {
			file >> chr;
			if (chr == ']') break;
			file.putback(chr);
			val = new float[3];
			for (int i = 0; i < 3; i++) {
				file >> buf;
				val[i] = buf;
			}
			vector->vector.push_back(val);
		}
	} while (str != "]");

	return str;
}


string getCoordIndex(ifstream& file, IndexedFaceSet* coord, string str) {
	int buf;
	char chr;
	vector<int> val;

	file >> str;
	if (str == "[") {
		do {
			file >> chr;
			if (chr == ']') break;
			file.putback(chr);
			file >> buf;
			while (buf != -1) {
				val.push_back(buf);
				file.get();
				file >> buf;
			}
			file >> chr;
			coord->coordIndex.push_back(val);
			val.clear();
		} while (str != "]" && chr != ']');
	}

	return str;
}


string getCoordIndex(ifstream& file, IndexedLineSet* coord, string str) {
	int buf;
	char chr;

	do {
		file.get(chr);
	} while (chr != '[');

	file >> buf;
	while (buf != -1) {
		coord->coordIndex.push_back(buf);
		file >> buf;
	}
	file >> str;

	return str;
}


string getNormIndex(ifstream& file, IndexedFaceSet* coord, string str) {
	int buf;
	char chr;
	vector<int> val;

	file >> str;
	if (str == "[") {
		do {
			file >> chr;
			if (chr == ']') break;
			file.putback(chr);
			file >> buf;
			while (buf != -1) {
				val.push_back(buf);
				file.get();
				file >> buf;
			}
			file >> chr;
			coord->normalIndex.push_back(val);
			val.clear();
		} while (str != "]" && chr != ']');
	}

	return str;
}