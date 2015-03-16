#pragma once

#include "Matrix4.h"
#include "Node.h"
#include <GL/glut.h>
#include "Window.h"

class Geode : public Node
{
public:
	Geode();
	~Geode();

	virtual void render() = 0;

	void draw(Matrix4 C);
	void update();
};

