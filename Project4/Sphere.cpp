#include "Sphere.h"


Sphere::Sphere(int size_)
{
	size = size_;
}


Sphere::~Sphere()
{
}

void Sphere::render(){
	glutSolidSphere(size, 0, 0);
}