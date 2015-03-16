#include "Robot.h"


Cube torso(1);
Cube head(1);
Cube rightArm(1);
Cube leftArm(1);
Cube rightLeg(1);
Cube leftLeg(1);

Robot::Robot()
{
	this->addChild(&ret);

	//torso
	torsoScale.scale(2, 2, 2);
	torsoScale.addChild(&torso);
	ret.addChild(&torsoScale);

	//head
	headTrans.translate(0, 1.5, 0);
	headTrans.addChild(&head);
	ret.addChild(&headTrans);

	//rightArm
	rightArmTrans2.translate(0, 1.5, 0);
	rightArmRotate.rotateX(angle);
	rightArmTrans1.translate(1.3, 1.5, 0);
	rightArmScale.scale(.5, 1.5, 1);

	ret.addChild(&rightArmTrans2);
	rightArmTrans2.addChild(&rightArmRotate);
	rightArmRotate.addChild(&rightArmTrans1);
	rightArmTrans1.addChild(&rightArmScale);
	rightArmScale.addChild(&rightArm);

	//leftArm
	leftArmTrans2.translate(0, 1.5, 0);
	leftArmRotate.rotateX(angle);
	leftArmTrans1.translate(-1.3, 1.5, 0);
	leftArmScale.scale(.5, 1.5, 1);

	ret.addChild(&leftArmTrans2);
	leftArmTrans2.addChild(&leftArmRotate);
	leftArmRotate.addChild(&leftArmTrans1);
	leftArmTrans1.addChild(&leftArmScale);
	leftArmScale.addChild(&leftArm);

	//rightLeg
	rightLegTrans2.translate(.1, -.3, 0);
	rightLegRotate.rotateX(angle);
	rightLegTrans1.translate(.4, -2, 0);
	rightLegScale.scale(.5, 2, 1);

	ret.addChild(&rightLegTrans2);
	rightLegTrans2.addChild(&rightLegRotate);
	rightLegRotate.addChild(&rightLegTrans1);
	rightLegTrans1.addChild(&rightLegScale);
	rightLegScale.addChild(&rightLeg);

	//leftLeg
	//leftLegTrans1.translate(-.4, -2, 0);
	//leftLegScale.scale(.5, 2, 1);

	leftLegTrans2.translate(-.8, -.3, 0);
	leftLegRotate.rotateX(angle);
	leftLegTrans1.translate(.4, -2, 0);
	leftLegScale.scale(.5, 2, 1);

	ret.addChild(&leftLegTrans2);
	leftLegTrans2.addChild(&leftLegRotate);
	leftLegRotate.addChild(&leftLegTrans1);
	leftLegTrans1.addChild(&leftLegScale);
	leftLegScale.addChild(&leftLeg);
}


Robot::~Robot()
{
}

void Robot::update(double d){
	if (whichWay){
		angle += 2;
		if (angle > d) whichWay = !whichWay;
	}
	else{
		angle -= 2;
		if (angle < -d) whichWay = !whichWay;
	}
}

void Robot::render(){
	//rightArm rotate
	rightArmRotate.rotateX(angle-180);
	leftArmRotate.rotateX(-(angle - 180));
	rightLegRotate.rotateX(-angle);
	leftLegRotate.rotateX(angle);
}