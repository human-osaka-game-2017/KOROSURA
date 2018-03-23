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
#include"CameraIvent.h"

class BoxCollider;
class Physics;
class EnemyLevel;

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

	//カメラとの距離変数を更新
	void UpdateDistance() {
		D3DXVECTOR3 distance = CameraIvent::GetInstance().GetCameraPos() - m_Pos;
		m_Distance = fabs(D3DXVec3Length(&distance));
	}


	//比較関数
	static bool cmp(EnemyBase* a, EnemyBase* b)
	{
		return (a->m_Distance < b->m_Distance);
	}

protected:
	const ENEMY_KIND kKind;

	Physics* m_pPhysics;
	Shape::OBB m_OBB;
	BoxCollider* m_pCollider;
	EnemyLevel* m_EnemyLevel;

private:
	const D3DXVECTOR3 kInitPos;//todo 基底クラスに持たせる
	const int kLevelFontOffset = 300;
	void Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects);
	//todo reaname
	float m_Angle_deg = 0;

	//カメラとの距離
	float m_Distance = 0;

	bool m_IsBoss = false;
	bool m_WasDead = false;
};
#endif