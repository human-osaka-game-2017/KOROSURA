#include"Physics.h"
#include"PhysicsManager.h"

Physics::Physics()
{
}

Physics::~Physics()
{
}

D3DXVECTOR3* Physics::GetRollVec(D3DXVECTOR3* rollVec)
{
	//法線
	D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

	//重力
	D3DXVECTOR3 gravity = PhysicsManager::GetInstance().GetGravity();

	//滑りベクトル S=L-(N * L)/(|N|^2)*N
	*rollVec = gravity - ((D3DXVec3Dot(&normalVec, &gravity)) / (pow(D3DXVec3Length(&normalVec), 2))) * normalVec;
	//*rollVec = normalVec + gravity;

	//正規化
	D3DXVec3Normalize(rollVec, rollVec);

	return rollVec;
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
	crossPos.x = (pow(normalVec.z, 2)*pos.x - normalVec.x*normalVec.z*pos.z) /
		(pow(normalVec.x, 2) + pow(normalVec.z, 2));
	crossPos.y = 0.0f;
	crossPos.z = -(normalVec.x / normalVec.z)*(pow(normalVec.z, 2)*pos.x - normalVec.x*normalVec.z*pos.z) /
		(pow(normalVec.x, 2) + pow(normalVec.z, 2));

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

float Physics::GetRollVelocity(bool isMoving)
{
	//速度更新
	float rad = 0.0f;
	{
		//法線
		D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

		float tmp = acos(normalVec.y / D3DXVec3Length(&normalVec));
		if (tmp > D3DXToRadian(90.0f)) {
			tmp = D3DXToRadian(180.0f) - tmp;
		}
		rad = tmp;
	}

	if (isMoving) {
		//if sinθ < μcosθ
		if (sin(rad) < PhysicsManager::GetInstance().GetDynamicCoefficientOfFriction()*cos(rad)) {
			m_Velocity = 0;
		}
		else {
			//絶対値
			float gravity = fabs(PhysicsManager::GetInstance().GetGravity().y);
			m_Velocity = gravity*sin(rad) - PhysicsManager::GetInstance().GetDynamicCoefficientOfFriction()*gravity*cos(rad);
		}
	}
	else {
		//if sinθ < μcosθ
		if (sin(rad) < PhysicsManager::GetInstance().GetStaticCoefficientOfFriction()*cos(rad)) {
			m_Velocity = 0;
		}
		else {
			//絶対値
			float gravity = fabs(PhysicsManager::GetInstance().GetGravity().y);
			m_Velocity = gravity*sin(rad) - PhysicsManager::GetInstance().GetDynamicCoefficientOfFriction()*gravity*cos(rad);
		}
	}


	//m_Velocity = a;

	return m_Velocity;
}

//float Physics::GetYLength(const D3DXVECTOR3& currentPos)
//{
//	////法線
//	//D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();
//
//	////地面のx-zの傾き
//	//float tmp = acos(normalVec.y / D3DXVec3Length(&normalVec));
//	//if (tmp > D3DXToRadian(90.0f)) {
//	//	tmp = D3DXToRadian(180.0f) - tmp;
//	//}
//	//float rad = tmp;
//
//	//static float preRad = 0.0f;
//
//	//float distanceRad = preRad - rad;
//
//	//preRad = rad;
//
//	////float ret = sqrt(pow(currentPos.x,2)+ pow(currentPos.z, 2)) * sin(rad)
//	////	+ currentPos.y * cos(rad);
//	//float ret = D3DXVec3Length(&currentPos)*sin(distanceRad);
//
//	//return ret;
//	return 0;
//}