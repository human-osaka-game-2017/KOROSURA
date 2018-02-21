#include"BoxCollider.h"
#include"SphereCollider.h"

BoxCollider::BoxCollider(const char* className, ObjectBase* pObject, Shape::OBB* pObb, std::function<void(std::vector<ObjectData*>*)> function, unsigned long categoryBits, unsigned long maskBits):
	ColliderBase(className,pObject,function,categoryBits,maskBits,Shape::SHAPE_ID::BOX),
	m_pObb(pObb)
{
}

BoxCollider::~BoxCollider()
{
}

bool BoxCollider::Collide(const ColliderBase& collider) const
{
	bool ret;

	switch (collider.GetShapeId()) {
	case Shape::SHAPE_ID::BOX:
		ret = CollideOBBToOBB(dynamic_cast<const BoxCollider&>(collider));
		break;

	default:
		MessageBox(0, "その形同士のあたり判定はできません", "", MB_OK);
		ret = false;
	}

	return ret;
}

bool BoxCollider::CollideOBBToSphere(const SphereCollider& collider) const
{
	//GetLengthOBBToPoint()
}

bool BoxCollider::CollideOBBToOBB(const BoxCollider& collider) const
{
	Shape::OBB	obb = collider.GetObb();

	// 各方向ベクトル、中心座標の距離の確保
	D3DXVECTOR3 NAe1 = m_pObb->GetDirect(0),	Ae1 = NAe1 *  m_pObb->GetLength(0);
	D3DXVECTOR3 NAe2 = m_pObb->GetDirect(1),	Ae2 = NAe2 *  m_pObb->GetLength(1);
	D3DXVECTOR3 NAe3 = m_pObb->GetDirect(2),	Ae3 = NAe3 *  m_pObb->GetLength(2);
	D3DXVECTOR3 NBe1 = obb.GetDirect(0),		Be1 = NBe1 * obb.GetLength(0);
	D3DXVECTOR3 NBe2 = obb.GetDirect(1),		Be2 = NBe2 * obb.GetLength(1);
	D3DXVECTOR3 NBe3 = obb.GetDirect(2),		Be3 = NBe3 * obb.GetLength(2);
	D3DXVECTOR3 Interval =  m_pObb->GetPos() - obb.GetPos();

	// 分離軸 : Ae1
	FLOAT rA = D3DXVec3Length(&Ae1);
	FLOAT rB = LenSegOnSeparateAxis(NAe1, Be1, Be2, &Be3);
	FLOAT L = fabs(D3DXVec3Dot(&Interval, &NAe1));
	if (L > rA + rB) {
		return false;

	}

	// 分離軸 : Ae2
	rA = D3DXVec3Length(&Ae2);
	rB = LenSegOnSeparateAxis(NAe2, Be1, Be2, &Be3);
	L = fabs(D3DXVec3Dot(&Interval, &NAe2));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : Ae3
	rA = D3DXVec3Length(&Ae3);
	rB = LenSegOnSeparateAxis(NAe3, Be1, Be2, &Be3);
	L = fabs(D3DXVec3Dot(&Interval, &NAe3));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : Be1
	rA = LenSegOnSeparateAxis(NBe1, Ae1, Ae2, &Ae3);
	rB = D3DXVec3Length(&Be1);
	L = fabs(D3DXVec3Dot(&Interval, &NBe1));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : Be2
	rA = LenSegOnSeparateAxis(NBe2, Ae1, Ae2,&Ae3);
	rB = D3DXVec3Length(&Be2);
	L = fabs(D3DXVec3Dot(&Interval, &NBe2));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : Be3
	rA = LenSegOnSeparateAxis(NBe3, Ae1, Ae2, &Ae3);
	rB = D3DXVec3Length(&Be3);
	L = fabs(D3DXVec3Dot(&Interval, &NBe3));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C11
	D3DXVECTOR3 Cross;
	D3DXVec3Cross(&Cross, &NAe1, &NBe1);
	rA = LenSegOnSeparateAxis(Cross, Ae2, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be2, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C12
	D3DXVec3Cross(&Cross, &NAe1, &NBe2);
	rA = LenSegOnSeparateAxis(Cross, Ae2, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C13
	D3DXVec3Cross(&Cross, &NAe1, &NBe3);
	rA = LenSegOnSeparateAxis(Cross, Ae2, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be2);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C21
	D3DXVec3Cross(&Cross, &NAe2, &NBe1);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be2, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C22
	D3DXVec3Cross(&Cross, &NAe2, &NBe2);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C23
	D3DXVec3Cross(&Cross, &NAe2, &NBe3);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be2);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C31
	D3DXVec3Cross(&Cross, &NAe3, &NBe1);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae2);
	rB = LenSegOnSeparateAxis(Cross, Be2, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C32
	D3DXVec3Cross(&Cross, &NAe3, &NBe2);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae2);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離軸 : C33
	D3DXVec3Cross(&Cross, &NAe3, &NBe3);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae2);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be2);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// 分離平面が存在しないので「衝突している」
	return true;
}

FLOAT BoxCollider::LenSegOnSeparateAxis(const D3DXVECTOR3& Sep, const D3DXVECTOR3& e1, const D3DXVECTOR3& e2, const D3DXVECTOR3* e3)const
{
	// 3つの内積の絶対値の和で投影線分長を計算
	// 分離軸Sepは標準化されていること
	FLOAT r1 = fabs(D3DXVec3Dot(&Sep, &e1));
	FLOAT r2 = fabs(D3DXVec3Dot(&Sep, &e2));
	FLOAT r3 = (e3 != nullptr) ? (fabs(D3DXVec3Dot(&Sep, e3))) : 0;
	return r1 + r2 + r3;
}