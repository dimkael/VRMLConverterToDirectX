#include "parseShape.h"
#include "parseNode.h"
#include "classMaterial.h"
#include "classIndexedFaceSet.h"
#include "classIndexedLineSet.h"
#include "classCoordinate.h"
#include "classNormal.h"
#include "getCoord.h"
#include "define.h"



void parseShape(ifstream& file, vector<Node*>* v, string def, string cur_file) {
	Shape* shape = new Shape(def);
	string str;
	float buf;
	float* val;
	bool next1 = false, next2 = false;

	
	do {
		file >> str;
		if (str == "DEF") file >> def;
		if (str == "Appearance") {
			next1 = true;
			do {
				file >> str;
				if (str == "DEF") {
					file >> def;
					def = def + "_" + cur_file;
				}
				else if (str == "Material") {
					next2 = true;
					Material* material = new Material(def);

					do {
						file >> str;
						if (str == "diffuseColor" || str == "emissiveColor" || str == "specularColor") {
							val = new float[3];
							for (int i = 0; i < 3; i++) {
								file >> buf;
								val[i] = buf;
							}
							material->materials.insert(pair<string, float*>(str, val));
						}
						if (str == "ambientIntensity" || str == "shininess" || str == "transparency") {
							val = new float;
							file >> *val;
							material->materials.insert(pair<string, float*>(str, val));
						}
					} while (str != "}");

					if (material->def != "") {
						DEF->insert(pair<string, Node*>(def, material));
						def.clear();
					}

					if (next2) {
						file >> str;
						next2 = false;
					}
					shape->appearance = material;
				}
				if (str == "USE") {
					file >> str;
					shape->appearance = (Appearance*)DEF->at(str + "_" + cur_file);
				}
			} while (str != "}");

			if (next1) {
				file >> str;
				next1 = false;
			}
		}
		if (str == "geometry") {
			file >> str;
			if (str == "DEF") {
				file >> def;
				def = def + "_" + cur_file;
				file >> str;
			}
			if (str == "IndexedFaceSet") {
				IndexedFaceSet* faceSet = new IndexedFaceSet(def);
				next1 = true;

				do {
					file >> str;
					if (str == "solid") {
						file >> str;
						if (str == "FALSE") {
							faceSet->solid = false;
						}
					}
					if (str == "coord") {
						do {
							file >> str;
							if (str == "DEF") {
								file >> def;
								def = def + "_" + cur_file;
							}
							if (str == "USE") {
								file >> str;
								faceSet->coord = (Coordinate*)DEF->at(str + "_" + cur_file);
								break;
							}
							if (str == "Coordinate") {
								next2 = true;

								Coordinate* coord = new Coordinate(def);
								str = getCoord(file, coord, str);

								if (coord->def != "") {
									DEF->insert(pair<string, Node*>(def, coord));
									def.clear();
								}

								if (next2) {
									file >> str;
									next2 = false;
								}
								faceSet->coord = coord;
							}
						} while (str != "}");
						file >> str;
					}
					if (str == "normal") {
						do {
							file >> str;
							if (str == "DEF") {
								file >> def;
								def = def + "_" + cur_file;
							}
							if (str == "USE") {
								file >> str;
								faceSet->normal = (Normal*)DEF->at(str + "_" + cur_file);
								break;
							}
							if (str == "Normal") {
								next2 = true;

								Normal* normal = new Normal(def);
								str = getNorm(file, normal, str);

								if (normal->def != "") {
									DEF->insert(pair<string, Node*>(def, normal));
									def.clear();
								}

								if (next2) {
									file >> str;
									next2 = false;
								}
								faceSet->normal = normal;
							}
						} while (str != "}");
						file >> str;
					}
					if (str == "coordIndex") {
						next2 = true;

						str = getCoordIndex(file, faceSet, str);

						if (next2) {
							file >> str;
							next2 = false;
						}
					}
					if (str == "normalIndex") {
						next2 = true;

						str = getNormIndex(file, faceSet, str);

						if (next2) {
							file >> str;
							next2 = false;
						}
					}
					if (str == "normalPerVertex") {
						file >> str;
						if (str == "FALSE") {
							faceSet->normalPerVertex = false;
						}
					}
				} while (str != "}");

				if (next1) {
					file >> str;
					next1 = false;
				}
				
				shape->geometry = faceSet;
			}
			if (str == "IndexedLineSet") {
				IndexedLineSet* lineSet = new IndexedLineSet(def);
				next1 = true;

				do {
					file >> str;
					if (str == "DEF") {
						file >> def;
						def = def + "_" + cur_file;
					}
					if (str == "Coordinate") {
						next2 = true;

						Coordinate* coord = new Coordinate(def);
						str = getCoord(file, coord, str);

						if (coord->def != "") {
							DEF->insert(pair<string, Node*>(def, coord));
							def.clear();
						}

						if (next2) {
							file >> str;
							file >> str;
							next2 = false;
						}
						lineSet->coord = coord;
					}
					if (str == "coordIndex") {
						next2 = true;

						str = getCoordIndex(file, lineSet, str);

						if (next2) {
							file >> str;
							next2 = false;
						}
					}
				} while (str != "}");

				if (next1) {
					file >> str;
					next1 = false;
				}
				shape->geometry = lineSet;
			}
			if (str == "USE") {
				file >> str;
				shape->geometry = (Geometry*)DEF->at(str + "_" + cur_file);
			}
		}
		if (str == "USE") {
			file >> str;
			shape = (Shape*)DEF->at(str + "_" + cur_file);
		}
	} while (str != "}");

	v->push_back(shape);

	if (shape->def != "") {
		DEF->insert(pair<string, Node*>(def, shape));
		def.clear();
	}
}