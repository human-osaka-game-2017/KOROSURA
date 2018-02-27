/**
 * @file	Slime.h
 * @brief	Slimeクラスのヘッダ
 * @author	shiraishi
 */

#ifndef SLIME_H
#define SLIME_H

#include"CharacterBase.h"

class Physics;

class Slime :public CharacterBase{
public:
	// D3DXVECTOR3& normalVec, int level
	Slime(D3DXVECTOR3& pos);
	virtual ~Slime();

	D3DXVECTOR3* GetPos() { return &m_Pos; }

	virtual void Update();
	virtual void Draw();

private:
	Physics* m_pPhysics;
	D3DXVECTOR3 LookPos;
};
#endif