#include"Physics.h"
#include"PhysicsManager.h"

Physics::Physics()
{
}

Physics::~Physics()
{
}

D3DXVECTOR3* Physics::GetRollVec(D3DXVECTOR3* rollVec, const D3DXVECTOR3& currentPos)
{
	//法線
	D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

	//現在のオブジェクト座標を平面上に投影した座標
	D3DXVECTOR3 pos = currentPos;
	pos.y = -((normalVec.x*pos.x + normalVec.z*pos.z) / pos.z);

	//平面とx-z平面の交差する直線と
	//currentPosを通る↑の直線の垂線
	//の交差する座標
	D3DXVECTOR3 crossPos;
	crossPos.x = ((pos.z*normalVec.z*normalVec.x) - pow(normalVec.z, 2)*pos.x)
		/ (pow(normalVec.x, 2) - pow(normalVec.z, 2));
	crossPos.y = 0.0f;
	crossPos.z = (normalVec.x / normalVec.z)*((pos.z*normalVec.z*normalVec.x) - pow(normalVec.z, 2)*pos.x)
		/ (pow(normalVec.x, 2) - pow(normalVec.z, 2));

	if (pos.y < 0) {
		*rollVec = pos - crossPos;
	}
	else {
		*rollVec = crossPos - pos;
	}

	//正規化
	D3DXVec3Normalize(rollVec, rollVec);

	return rollVec;
}

float Physics::GetRollVelocity()
{
	//法線
	D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

	//地面のx-zの傾き
	float rad = D3DX_PI - acos(normalVec.y / D3DXVec3Length(&normalVec));

	//if sinθ < μcosθ
	if (sin(rad) < PhysicsManager::GetInstance().GetStaticCoefficientOfFriction()*cos(rad)) {
		m_Velocity = 0;
	}
	else {
		float gravity = PhysicsManager::GetInstance().GetGravity();
		m_Velocity += gravity*sin(rad) - PhysicsManager::GetInstance().GetDynamicCoefficientOfFriction()*gravity*cos(rad);
	}

	return m_Velocity;
}