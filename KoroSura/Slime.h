/**
 * @file	Slime.h
 * @brief	Slimeクラスのヘッダ
 * @author	shiraishi
 */

#ifndef SLIME_H
#define SLIME_H

#include"CharacterBase.h"

class Slime :public CharacterBase{
public:
	//, D3DXVECTOR3& normalVec, int level
	Slime(D3DXVECTOR3& pos);
	virtual ~Slime();

	virtual void Update();
	virtual void Draw();
};
#endif