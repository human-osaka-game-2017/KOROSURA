/**
 * @file	EnemyBase.h
 * @brief	EnemyBaseクラスのヘッダ
 * @author	shiraishi
 */
#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include"CharacterBase.h"

class EnemyBase :public CharacterBase {
public:
	enum struct ENEMY_KIND {
		SPIDER,
		MAX
	};

	EnemyBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level, ENEMY_KIND kind):
		CharacterBase(pos,normalVec,level),
		m_Kind(kind)
	{}

	virtual ~EnemyBase() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	const ENEMY_KIND m_Kind;
};
#endif