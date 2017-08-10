#include "Parser.h"

Cparser::Cparser()
{

}

Cparser::~Cparser()
{

}

bool Cparser::OpenFile(const char * Filename) {
	Unnombre.open(Filename, fstream::in);
	if (!Unnombre.is_open()) {
		return false;
	}
	return true;

}

void Cparser::Literate(const char * Filename, vector<unsigned short> &index, vector<CVertex4> &Vertex) {
	if (OpenFile(Filename)) {
		getline(Unnombre, reader);
		if (reader == "xof 0303txt 0032") {
			while (!Unnombre.eof())
			{
				getline(Unnombre, reader);
				if (reader == " Mesh mesh_pinata_cerdo_ {") {
					 
					Unnombre >> NVertx >> Courrier;
					for (int i = 0; i < NVertx; i++) {
						CVertex4 V;
						Unnombre >> holder >> Courrier;
						V.x = holder;
						Unnombre >> holder >> Courrier;
						V.y = holder;
						Unnombre >> holder >> Courrier >> Courrier;
						V.z= holder;

						Vertex.push_back(V);
					}
					Unnombre >> NIndex >> Courrier;
					for (int i = 0; i < NIndex; i++) {
						unsigned short Ind;
						Unnombre >> Courrier >> Courrier >> holder >> Courrier;
						Ind = holder;
						index.push_back(Ind);
						Unnombre >> holder >> Courrier;
						Ind = holder;
						index.push_back(Ind);
						Unnombre >> holder >> Courrier >> Courrier;
						Ind = holder;
						index.push_back(Ind);						
					}
				}
			}
		}
		Unnombre.close();
	}

}