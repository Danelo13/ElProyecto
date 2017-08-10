#ifndef UAD_MESH_GL_H
#define UAD_MESH_GL_H

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "MATRIX4D.h"

#include "PrimitiveBase.h"
#include "UtilsGL.h"
#include "Parser.h"


//struct CVertex {
//
//	float x, y, z, w;
//	float nx, ny, nz, nw;
//	float s, t;
//};

class MeshGL : public PrimitiveBase {
public:
	MeshGL() : shaderID(0) {}
	void Create() {};
	void Create(char *File);
	void Transform(float *t);
	void Draw(float *t, float *vp);
	void Destroy();

	GLuint	shaderID;
	GLint	vertexAttribLoc;
	GLint	normalAttribLoc;
	GLint	uvAttribLoc;

	GLint  matWorldViewProjUniformLoc;
	GLint  matWorldUniformLoc;

	vector <CVertex4>			vertices;
	vector <unsigned short>	indices;
	GLuint			VB;
	GLuint			IB;

	Cparser Parseador;

	MATRIX4D	transform;
};


#endif