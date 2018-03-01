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
	Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level);
	virtual ~Slime();

	D3DXVECTOR3* GetPos() { return &m_Pos; }

	virtual void Update();
	virtual void Draw();
	virtual void DrawPreparation();

private:
	const D3DXVECTOR3 kInitialPos;
	Physics* m_pPhysics;
};
#endif