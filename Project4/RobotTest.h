#pragma once
#include "MatrixTransform.h"
class RobotTest
{
private:
	MatrixTransform test;
public:

	MatrixTransform getTransform();

	RobotTest();
	~RobotTest();
};

