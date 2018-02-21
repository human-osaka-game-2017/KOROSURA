#include"Physics.h"
#include"PhysicsManager.h"

Physics::Physics()
{

}

Physics::~Physics()
{
}

D3DXVECTOR3* Physics::GetFallVec(D3DXVECTOR3* fallVec, const D3DXVECTOR3& currentPos)
{
	//法線
	D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

	//地面のX軸方向ベクトル
	D3DXVECTOR3 groundVecX = PhysicsManager::GetInstance().GetSlope()[0];

	//現在のオブジェクト座標を平面上に投影した座標
	D3DXVECTOR3 pos = currentPos;
	pos.y = (normalVec.x*(groundVecX.x - currentPos.x)) / normalVec.y + groundVecX.y + (normalVec.z*(groundVecX.z - currentPos.z)) / normalVec.y;

	//平面とx-z平面の交差する直線と
	//currentPosを通る↑の直線の垂線
	//の交差する座標
	D3DXVECTOR3 crossPos;
	crossPos.x = (pow(normalVec.z, 2)*pos.x + normalVec.z*(normalVec.z*groundVecX.x + normalVec.y*groundVecX.y + normalVec.z*groundVecX.z - normalVec.z*pos.z)) /
		(pow(normalVec.z, 2) + pow(normalVec.x, 2));
	crossPos.y = 0.0f;
	crossPos.z = pow(normalVec.z, 3)*pos.x + normalVec.x*normalVec.z*(normalVec.z*groundVecX.x + normalVec.y*groundVecX.y + normalVec.z*groundVecX.z - normalVec.z*pos.z) /
		(normalVec.x*(pow(normalVec.z, 2) + pow(normalVec.x, 2))) + pos.z - (pos.x*normalVec.z) / normalVec.x;

	if (pos.y < 0) {
		*fallVec = pos - crossPos;
	}
	else {
		*fallVec = crossPos - pos;
	}

	//正規化
	D3DXVec3Normalize(fallVec, fallVec);

	return fallVec;
}
