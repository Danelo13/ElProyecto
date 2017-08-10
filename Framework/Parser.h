#pragma once
#include <fstream>
#include <string>
#include "MATRIX4D.h"
#include <vector>

using namespace std;

struct CVertex4 {
	CVertex4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f){}

	float x, y, z, w;

};

class Cparser {
public:
	Cparser();
	~Cparser();

	bool OpenFile(const char * Filename);

	fstream Unnombre;

	string reader;
	int NVertx;
	int NIndex;
	char Courrier;
	float holder;

	void Literate(const char * Filename, vector<unsigned short> &index, vector<CVertex4> &Vertex);
};