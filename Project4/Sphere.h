#pragma once
#include "Geode.h"

class Sphere : public Geode
{
public:
	int size;

	Sphere(int);
	~Sphere();

	void render();
};

