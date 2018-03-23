#ifndef PLAYERLEVEL_H
#define PLAYERLEVEL_H

#include"ObjectBase.h"
#include"Utility.h"

#define BackGround_W 460
#define BackGround_H 200
#define SLIME_WEIGHT 100
#define SLIME_HEIGHT 100

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
	const D3DXVECTOR2 m_BackGroundPos;
	const D3DXVECTOR2 m_MinslimePos;


};

#endif