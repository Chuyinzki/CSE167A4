#pragma once
#include "Geode.h"

class Cube : public Geode
{
public:
	int size;

	Cube(int);
	Cube();
	~Cube();

	void render();
};

