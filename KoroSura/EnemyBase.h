/**
 * @file	EnemyBase.h
 * @brief	EnemyBaseクラスのヘッダ
 * @author	shiraishi
 */
#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include"CharacterBase.h"
#include"Shape.h"
#include"ColliderBase.h"

class BoxCollider;
class Physics;

class EnemyBase :public CharacterBase {
public:
	enum struct ENEMY_KIND {
		SLIME,
		MUSHROOM_RED,
		MUSHROOM_BLUE,
		MUSHROOM_PURPLE,
		GOBLIN,
		GOBLIN_PURPLE,//murasaki
		TRENT_GREEN,
		TRENT_YELLOW,
		TRENT_PINK,
		CERBERUS,
		TIGER,
		MINOTAUR,
		MAX
	};

	EnemyBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level, ENEMY_KIND kind, float angleDeg, bool isBoss);

	virtual ~EnemyBase();

	virtual void Update();
	virtual void Draw();

	BoxCollider* GetCollider() { return m_pCollider; }

	void Dead() { m_WasDead = true; }
	bool WasDead() { return m_WasDead; }

	bool IsBoss() { return m_IsBoss; }

protected:
	const ENEMY_KIND kKind;

	Physics* m_pPhysics;
	Shape::OBB m_OBB;
	BoxCollider* m_pCollider;

private:
	const D3DXVECTOR3 kInitPos;//todo 基底クラスに持たせる
	void Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects);
	//todo reaname
	float m_Angle_deg = 0;
	bool m_IsBoss = false;
	bool m_WasDead = false;
};
#endif