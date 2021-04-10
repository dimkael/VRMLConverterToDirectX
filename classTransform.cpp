#include "classTransform.h"
#include "define.h"


Transform::Transform() : scale{ 1, 1, 1 }, translation{ 0, 0, 0 }, rotation{ 0, 0, 0, 0 }, children(new vector<Node*>) {}

Transform::Transform(string _def) : scale{ 1, 1, 1 }, translation{ 0, 0, 0 }, rotation{ 0, 0, 0, 0 }, children(new vector<Node*>), Node(_def) {}

void Transform::setTransformMatrix(float** matrix) {
	float scaleMatrix[4][4] = { 0 };
	float translationMatrix[4][4] = { 0 };
	float rotationMatrix[4][4] = { 0 };
	float buf[4][4] = { 0 };

	for (int i = 0; i < 3; i++) {
		scaleMatrix[i][i] = scale[i];
	}
	scaleMatrix[3][3] = 1;

	for (int i = 0; i < 3; i++) {
		translationMatrix[i][i] = 1;
		translationMatrix[3][i] = translation[i];
	}
	translationMatrix[3][3] = 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				rotationMatrix[i][j] = cos(rotation[3]) + (1 - cos(rotation[3])) * rotation[i] * rotation[i];
			}
			else if (i == j - 1 || j == i - 2) {
				rotationMatrix[i][j] = (1 - cos(rotation[3])) * rotation[i] * rotation[j] + sin(rotation[3]) * rotation[(j + 1) % 3];
			}
			else if (i == j - 2 || j == i - 1) {
				rotationMatrix[i][j] = (1 - cos(rotation[3])) * rotation[i] * rotation[j] - sin(rotation[3]) * rotation[abs(j - 1) % 3];
			}
		}
	}
	rotationMatrix[3][3] = 1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				buf[i][j] += rotationMatrix[i][k] * scaleMatrix[k][j];
				matrix[i][j] = 0.0;
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				matrix[i][j] += buf[i][k] * translationMatrix[k][j];
			}
		}
	}
}

void Transform::writeX(ofstream& file) {
	file << "Frame " << this->def << " {\n";
	file << "   FrameTransformMatrix {\n";

	float** matrix = new float* [4];
	for (int i = 0; i < 4; i++) {
		matrix[i] = new float[4];
	}
	setTransformMatrix(matrix);

	if (lastMatrix == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == 3) {
					if (i == 3)
						file << matrix[i][j] << ";;\n";
					else
						file << matrix[i][j] << ",\n";
				}
				else
					file << matrix[i][j] << ",";
			}
		}
		file << "}\n";

		lastMatrix = matrix;

		vector<Node*>::iterator it;
		for (it = children->begin(); it != children->end(); it++) {
			(*it)->writeX(file);
		}
		file << "}\n";

		/*for (int i = 0; i < 4; i++) {
			delete[] lastMatrix[i];
		}
		delete[] lastMatrix;*/
	}
	else {
		float buf[3];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				buf[j] = 0;
				for (int k = 0; k < 3; k++) {
					buf[j] += lastMatrix[i][k] * matrix[k][j];
				}
			}
			for (int j = 0; j < 3; j++) {
				matrix[i][j] = buf[j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == 3) {
					if (i == 3)
						file << matrix[i][j] << ";;\n";
					else
						file << matrix[i][j] << ",\n";
				}
				else
					file << matrix[i][j] << ",";
			}
		}
		file << "}\n";

		lastMatrix = matrix;

		vector<Node*>::iterator it;
		for (it = children->begin(); it != children->end(); it++) {
			(*it)->writeX(file);
		}
		file << "}\n";
	}

	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 3) {
				file << 0 << ",";
				continue;
			}
			if (i == j) {
				file << cos(rotation[3]) + (1 - cos(rotation[3])) * rotation[i] * rotation[i] * scale[i] << ",";
			}
			else if (i == j - 1 || j == i - 2) {
				file << (1 - cos(rotation[3])) * rotation[i] * rotation[j] + sin(rotation[3]) * rotation[(j + 1) % 3] << ",";
			}
			else if (i == j - 2 || j == i - 1) {
				file << (1 - cos(rotation[3])) * rotation[i] * rotation[j] - sin(rotation[3]) * rotation[abs(j - 1) % 3] << ",";
			}
		}
		file << "\n";
	}

	for (int i = 0; i < 4; i++) {
		if (i < 3)
			file << translation[i] << ",";
		else
			file << 1 << ";;\n";
	}
	file << "}\n";*/
}

Transform::~Transform() {
	//if (def == "")
		del(children);
}