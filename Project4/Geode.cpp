#include "Geode.h"
#include "main.h"


Geode::Geode()
{
}


Geode::~Geode()
{
}

void Geode::draw(Matrix4 C){
	C.transpose();
	glLoadMatrixd(C.getPointer());
	C.transpose();

	Vector4 elCentro = C * Vector4(0,0,0,1);
	Vector4 laScala = C * Vector4(0.5, 0.5, 0.5, 0);

	render();

	if (Window::bounding){
		glColor3f(1, 0, 0);

		Matrix4 trans;
		trans.identity();
		trans.makeTranslate(elCentro.get(0), elCentro.get(1), elCentro.get(2));

		Matrix4 scale;
		scale.identity();
		Vector3 v3laScala(laScala.get(0), laScala.get(1), laScala.get(2));
		scale.makeScale(v3laScala.length(), v3laScala.length(), v3laScala.length());

		Matrix4 result = trans * scale;
		result.transpose();
		glPushMatrix();
		glLoadMatrixd(result.getPointer());

		
		glutWireSphere(1,10,10);
		glPopMatrix();
	}
}

void Geode::update(){

}