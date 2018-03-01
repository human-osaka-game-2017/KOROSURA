#ifndef LIMITTIME_H
#define LIMITTIME_H

#include"ObjectBase.h"
#include"Utility.h"


class LimitTime : public ObjectBase 
{
public:
	LimitTime();
	virtual ~LimitTime();

	virtual void Update();

	virtual void Draw();
private:
	void NextCharPos(Utility::CUSTOMVERTEX vertex[]);

	const D3DXVECTOR2 m_Pos;

};

#endif