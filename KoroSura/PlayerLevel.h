#ifndef PLAYERLEVEL_H
#define PLAYERLEVEL_H

#include"ObjectBase.h"
#include"Utility.h"

class PlayerLevel : public ObjectBase{
public:
	PlayerLevel();
	virtual ~PlayerLevel();

	virtual void Update();

	void Draw(int level);
	virtual void Draw() {}

private:
	void NextCharPos(Utility::CUSTOMVERTEX vertex[]);

	const D3DXVECTOR2 m_Pos;
};

#endif