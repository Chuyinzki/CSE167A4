#pragma once
#include "Group.h"
#include "Matrix4.h"

class MatrixTransform : public Group
{
private:
	Matrix4 M;

public:
	MatrixTransform();
	~MatrixTransform();

	void draw(Matrix4);
	void translate(double, double, double);
	void scale(double, double, double);
	void rotate(double, Vector3&);
	void rotateX(double);
};

