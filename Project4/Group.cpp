#include "Group.h"


Group::Group()
{
}


Group::~Group()
{
}

void Group::draw(Matrix4 C){
	for (list<Node*>::iterator ci = listy.begin(); ci != listy.end(); ++ci){
		(*ci)->draw(C);
	}
}

void Group::update(){

}

void Group::addChild(Node* child){
	listy.push_back(child);
}

void Group::removeChild(Node* toRemove){
	for (list<Node*>::iterator ci = listy.begin(); ci != listy.end(); ++ci){
		if ((*ci) == toRemove){
			listy.erase(ci);
		}
	}
}