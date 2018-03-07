#ifndef TITLEBACKGROUND_H
#define TITLEBACKGROUND_H

#include "ObjectBase.h"

class TitleBackground :public ObjectBase{
public:
	TitleBackground();
	virtual ~TitleBackground();

	virtual void Update() {};
	virtual void Draw();
};
#endif