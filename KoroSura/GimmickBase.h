/**
 * @file	GimmickBase.h
 * @brief	GimmickBaseクラスのヘッダ
 * @author	shiraishi
 */
#ifndef GIMMICKBASE_H
#define GIMMICKBASE_H

#include"MaterialBase.h"
#include"Shape.h"
#include"ColliderBase.h"

class BoxCollider;
class Physics;

class GimmickBase :public MaterialBase {
public:
	enum struct GIMMICK_KIND {
		FENCE, //!柵
		MAX
	};

	GimmickBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, GIMMICK_KIND kind, float angleDeg);
	virtual ~GimmickBase();

	virtual void Update();
	virtual void Draw();

	BoxCollider* GetCollider() { return m_pCollider; }

private:
	void Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects);

	const GIMMICK_KIND kKind;
	const D3DXVECTOR3 kInitPos;//todo 基底クラスに持たせる

	Physics* m_pPhysics;
	BoxCollider* m_pCollider;
	Shape::OBB m_OBB;
	float m_Angle_deg = 0;
};
#endif