#pragma once
#include "Window.h"

#include "Matrix4.h"
#include <string>

using namespace std;

class Node
{

public:
	Node();
	~Node();
	virtual void draw(Matrix4 C) = 0;
	virtual void update() = 0;

	Vector3 centerPoint;
	double radius;
};

