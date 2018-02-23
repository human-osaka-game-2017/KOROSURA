/**
 * @file	CharacterBase.h
 * @brief	CharacterBaseクラスのヘッダ
 * @author	shiraishi
 */
#ifndef CHARACTERBASE_H
#define CHARACTERBASE_H

#include"MaterialBase.h"

class CharacterBase :public MaterialBase {
public:
	CharacterBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level):
		MaterialBase(pos,normalVec),
		m_Level(level)
	{}
	CharacterBase(D3DXVECTOR3& pos) : MaterialBase(pos){ m_Pos = pos; }

	virtual ~CharacterBase() {};

	int GetLevel() {
		return m_Level;
	}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	int m_Level = 1;
};
#endif