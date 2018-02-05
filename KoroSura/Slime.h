/**
 * @file	Slime.h
 * @brief	Slime�N���X�̃w�b�_
 * @author	shiraishi
 */

#ifndef SLIME_H
#define SLIME_H

#include"CharacterBase.h"

class Slime :public CharacterBase{
public:
	Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level);
	virtual ~Slime();

	virtual void Update();
	virtual void Draw();
};
#endif