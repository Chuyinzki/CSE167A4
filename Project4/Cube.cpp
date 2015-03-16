#include "Cube.h"


Cube::Cube(int size_)
{
	size = size_;
}

Cube::Cube()
{
	
}


Cube::~Cube()
{
}

void Cube::render(){
	//printf("Calling render\n");
	glColor3f(0,1,0);
	glutSolidCube(size);

}