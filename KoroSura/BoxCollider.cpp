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
		MessageBox(0, "���̌`���m�̂����蔻��͂ł��܂���", "", MB_OK);
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

	// �e�����x�N�g���A���S���W�̋����̊m��
	D3DXVECTOR3 NAe1 = m_pObb->GetDirect(0),	Ae1 = NAe1 *  m_pObb->GetLength(0);
	D3DXVECTOR3 NAe2 = m_pObb->GetDirect(1),	Ae2 = NAe2 *  m_pObb->GetLength(1);
	D3DXVECTOR3 NAe3 = m_pObb->GetDirect(2),	Ae3 = NAe3 *  m_pObb->GetLength(2);
	D3DXVECTOR3 NBe1 = obb.GetDirect(0),		Be1 = NBe1 * obb.GetLength(0);
	D3DXVECTOR3 NBe2 = obb.GetDirect(1),		Be2 = NBe2 * obb.GetLength(1);
	D3DXVECTOR3 NBe3 = obb.GetDirect(2),		Be3 = NBe3 * obb.GetLength(2);
	D3DXVECTOR3 Interval =  m_pObb->GetPos() - obb.GetPos();

	// ������ : Ae1
	FLOAT rA = D3DXVec3Length(&Ae1);
	FLOAT rB = LenSegOnSeparateAxis(NAe1, Be1, Be2, &Be3);
	FLOAT L = fabs(D3DXVec3Dot(&Interval, &NAe1));
	if (L > rA + rB) {
		return false;

	}

	// ������ : Ae2
	rA = D3DXVec3Length(&Ae2);
	rB = LenSegOnSeparateAxis(NAe2, Be1, Be2, &Be3);
	L = fabs(D3DXVec3Dot(&Interval, &NAe2));
	if (L > rA + rB) {
		return false;
	}

	// ������ : Ae3
	rA = D3DXVec3Length(&Ae3);
	rB = LenSegOnSeparateAxis(NAe3, Be1, Be2, &Be3);
	L = fabs(D3DXVec3Dot(&Interval, &NAe3));
	if (L > rA + rB) {
		return false;
	}

	// ������ : Be1
	rA = LenSegOnSeparateAxis(NBe1, Ae1, Ae2, &Ae3);
	rB = D3DXVec3Length(&Be1);
	L = fabs(D3DXVec3Dot(&Interval, &NBe1));
	if (L > rA + rB) {
		return false;
	}

	// ������ : Be2
	rA = LenSegOnSeparateAxis(NBe2, Ae1, Ae2,&Ae3);
	rB = D3DXVec3Length(&Be2);
	L = fabs(D3DXVec3Dot(&Interval, &NBe2));
	if (L > rA + rB) {
		return false;
	}

	// ������ : Be3
	rA = LenSegOnSeparateAxis(NBe3, Ae1, Ae2, &Ae3);
	rB = D3DXVec3Length(&Be3);
	L = fabs(D3DXVec3Dot(&Interval, &NBe3));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C11
	D3DXVECTOR3 Cross;
	D3DXVec3Cross(&Cross, &NAe1, &NBe1);
	rA = LenSegOnSeparateAxis(Cross, Ae2, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be2, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C12
	D3DXVec3Cross(&Cross, &NAe1, &NBe2);
	rA = LenSegOnSeparateAxis(Cross, Ae2, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C13
	D3DXVec3Cross(&Cross, &NAe1, &NBe3);
	rA = LenSegOnSeparateAxis(Cross, Ae2, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be2);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C21
	D3DXVec3Cross(&Cross, &NAe2, &NBe1);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be2, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C22
	D3DXVec3Cross(&Cross, &NAe2, &NBe2);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C23
	D3DXVec3Cross(&Cross, &NAe2, &NBe3);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae3);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be2);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C31
	D3DXVec3Cross(&Cross, &NAe3, &NBe1);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae2);
	rB = LenSegOnSeparateAxis(Cross, Be2, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C32
	D3DXVec3Cross(&Cross, &NAe3, &NBe2);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae2);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be3);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// ������ : C33
	D3DXVec3Cross(&Cross, &NAe3, &NBe3);
	rA = LenSegOnSeparateAxis(Cross, Ae1, Ae2);
	rB = LenSegOnSeparateAxis(Cross, Be1, Be2);
	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (L > rA + rB) {
		return false;
	}

	// �������ʂ����݂��Ȃ��̂Łu�Փ˂��Ă���v
	return true;
}

FLOAT BoxCollider::LenSegOnSeparateAxis(const D3DXVECTOR3& Sep, const D3DXVECTOR3& e1, const D3DXVECTOR3& e2, const D3DXVECTOR3* e3)const
{
	// 3�̓��ς̐�Βl�̘a�œ��e���������v�Z
	// ������Sep�͕W��������Ă��邱��
	FLOAT r1 = fabs(D3DXVec3Dot(&Sep, &e1));
	FLOAT r2 = fabs(D3DXVec3Dot(&Sep, &e2));
	FLOAT r3 = (e3 != nullptr) ? (fabs(D3DXVec3Dot(&Sep, e3))) : 0;
	return r1 + r2 + r3;
}