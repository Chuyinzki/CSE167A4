#pragma once
#include "MatrixTransform.h"
#include "RobotPart.h"
#include "Cube.h"
#include "Sphere.h"

class Robot : public Group
{
public:
	double angle = 0;
	Vector3 vecy;
	bool whichWay = false;

	//Cube leftLeg, rightLeg, rightArm, leftArm, head, torso;

	MatrixTransform torsoScale;

	MatrixTransform headTrans;

	MatrixTransform rightArmTrans1;
	MatrixTransform rightArmTrans2;
	MatrixTransform rightArmScale;
	MatrixTransform rightArmRotate;

	MatrixTransform leftArmTrans1;
	MatrixTransform leftArmTrans2;
	MatrixTransform leftArmScale;
	MatrixTransform leftArmRotate;

	MatrixTransform rightLegTrans1;
	MatrixTransform rightLegTrans2;
	MatrixTransform rightLegScale;
	MatrixTransform rightLegRotate;

	MatrixTransform leftLegTrans1;
	MatrixTransform leftLegTrans2;
	MatrixTransform leftLegScale;
	MatrixTransform leftLegRotate;

	Group ret;

	void update(double);
	void render();

	Robot();
	~Robot();
};

