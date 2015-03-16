#pragma once
#include "MatrixTransform.h"
#include "Geode.h"

class RobotPart
{
public:
	RobotPart();
	~RobotPart();

	MatrixTransform translation1, translation2, rotation, scale;
	Geode *part;
};

