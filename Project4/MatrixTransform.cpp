#include "MatrixTransform.h"


MatrixTransform::MatrixTransform()
{
	M.identity();
}


MatrixTransform::~MatrixTransform()
{
}

void MatrixTransform::draw(Matrix4 C){
	Matrix4 C_new = C*M;
	Group::draw(C_new);
	/*for (list<Node*>::iterator ci = listy.begin(); ci != listy.end(); ++ci){
		(*ci)->draw(C_new);
	}*/
}

void MatrixTransform::translate(double a, double b, double c){
	M.makeTranslate(a, b, c);
}

void MatrixTransform::scale(double a, double b, double c){
	M.makeScale(a, b, c);
}

void MatrixTransform::rotate(double i, Vector3& poo){
	M.makeRotate(i, poo);
}

void MatrixTransform::rotateX(double i){
	M.makeRotateX(i);
}
