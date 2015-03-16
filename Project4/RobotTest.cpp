#include "RobotTest.h"
#include "Cube.h"


RobotTest::RobotTest()
{
	//torso
	/*
	Cube torso(1);
	MatrixTransform torsoScale;
	torsoScale.scale(2, 2, 2);
	torsoScale.addChild(&torso);
	test.addChild(&torsoScale);
	*/

	Cube* cubePtr = new Cube(1);
	MatrixTransform* torsoScale = new MatrixTransform();
	torsoScale->scale(2, 2, 2);
	test.addChild(torsoScale);
	torsoScale->addChild(cubePtr);


	

}


RobotTest::~RobotTest()
{
}

MatrixTransform RobotTest::getTransform(){
	return test;
}