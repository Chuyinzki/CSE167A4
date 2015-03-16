#pragma once
#include <list>
#include "Node.h"

using namespace std;

class Group : public Node
{


public:
	Group();
	~Group();

	virtual void addChild(Node*);
	virtual void removeChild(Node*);

	virtual void draw(Matrix4 C);
	virtual void update();

	list<Node*> listy;
};

