#ifndef OBJECTBASE_H
#define OBJECTBASE_H

class ObjectBase{
public:
	ObjectBase() {};
	virtual ~ObjectBase() {};

	virtual void Update() = 0;
	virtual void Draw() = 0;
};
#endif