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
#include<vector>

class Physics;
class SphereCollider;

class Slime :public CharacterBase{
public:
	Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level);
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
};
#endif