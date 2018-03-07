/**
 * @file	Slime.h
 * @brief	Slimeクラスのヘッダ
 * @author	shiraishi
 */

#ifndef SLIME_H
#define SLIME_H

#include"CharacterBase.h"
#include"Shape.h"
#include"ColliderBase.h"
#include"SceneBase.h"
#include<vector>

class Physics;
class SphereCollider;
class PlayerLevel;

class Slime :public CharacterBase{
public:
	Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level, std::function<void(SceneBase::SCENE_ID)> function);
	virtual ~Slime();

	D3DXVECTOR3* GetPos() { return &m_Pos; }

	virtual void Update();
	virtual void Draw();

private:
	void Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects);

	const D3DXVECTOR3 kInitialPos;
	Physics* m_pPhysics;
	Shape::Sphere m_Sphere;
	SphereCollider* m_pCollider;
	PlayerLevel* m_pPlayerLevel;
	std::function<void(SceneBase::SCENE_ID)> m_Function;
	D3DXVECTOR3 m_Acceleration = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	bool m_IsFall = true;
};
#endif