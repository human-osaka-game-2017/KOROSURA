#include"PhysicsManager.h"
#include"InitProperty.h"
#include"Matrix.h"
#include"Lib.h"

PhysicsManager* PhysicsManager::m_pInstance = nullptr;

PhysicsManager::PhysicsManager():
	kGravity(D3DXVECTOR3(0.0f, -InitProperty::GetInstance().GetInitialData().gravity, 0.0f)),
	kSlopingDeg(InitProperty::GetInstance().GetInitialData().deg),
	kDynamicCoefficientOfFriction(InitProperty::GetInstance().GetInitialData().dynamicCoefficientOfFriction),
	kStaticCoefficientOfFriction(InitProperty::GetInstance().GetInitialData().staticCoefficientOfFriction),
	m_NormalVector(D3DXVECTOR3(0.0f,1.0f, 0.0f))
{
	m_pRot_mat = new D3DXMATRIXA16;
	D3DXMatrixIdentity(m_pRot_mat);
	//m_SlopeDeg[0] = 0.0f;
	//m_SlopeDeg[1] = 0.0f;
}

PhysicsManager::~PhysicsManager()
{
	delete m_pRot_mat;
}


void PhysicsManager::Update()
{
	D3DXVECTOR2 cameraXZ = D3DXVECTOR2(m_CameraVec.x, m_CameraVec.z);

	//カメラのy軸中心の回転角度
	float deg = Utility::AtanDeg(cameraXZ);
	const float rad = D3DXToRadian(deg);

	D3DXVECTOR3 axis = m_CameraVec;
	bool pushedKey = false;
	{
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::W) == Utility::BUTTON_STATE::ON ||
			Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::ON) {
			//m_SlopeDeg[0] += kSlopingDeg*sin(rad);
			//m_SlopeDeg[1] -= kSlopingDeg*cos(rad);
			axis = D3DXVECTOR3(m_CameraVec.z, 0.0f, -m_CameraVec.x);
			RotTerrain(axis);
		}

		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::A) == Utility::BUTTON_STATE::ON ||
			Lib::GetInstance().GetKeyState(Utility::KEY_KIND::LEFT) == Utility::BUTTON_STATE::ON) {
			//m_SlopeDeg[0] += kSlopingDeg*sin(rad + D3DX_PI / 2);
			//m_SlopeDeg[1] -= kSlopingDeg*cos(rad + D3DX_PI / 2);
			axis = D3DXVECTOR3(m_CameraVec.x, 0.0f, m_CameraVec.z);
			RotTerrain(axis);
		}

		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::S) == Utility::BUTTON_STATE::ON ||
			Lib::GetInstance().GetKeyState(Utility::KEY_KIND::DOWN) == Utility::BUTTON_STATE::ON) {
			axis = D3DXVECTOR3(-m_CameraVec.z, 0.0f, m_CameraVec.x);
			RotTerrain(axis);
			//m_SlopeDeg[0] -= kSlopingDeg*sin(rad);
			//m_SlopeDeg[1] += kSlopingDeg*cos(rad);
		}

		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::D) == Utility::BUTTON_STATE::ON ||
			Lib::GetInstance().GetKeyState(Utility::KEY_KIND::RIGHT) == Utility::BUTTON_STATE::ON) {
			//m_SlopeDeg[0] -= kSlopingDeg*sin(rad + D3DX_PI / 2);
			//m_SlopeDeg[1] += kSlopingDeg*cos(rad + D3DX_PI / 2);
			axis = D3DXVECTOR3(-m_CameraVec.x, 0.0f, -m_CameraVec.z);
			RotTerrain(axis);
		}
	}

	//上限
	//if (m_SlopeDeg[0] < -kMaxSlope) {
	//	m_SlopeDeg[0] = -kMaxSlope;
	//}
	//else if (m_SlopeDeg[0] > kMaxSlope) {
	//	m_SlopeDeg[0] = kMaxSlope;
	//}
	//if (m_SlopeDeg[1] < -kMaxSlope) {
	//	m_SlopeDeg[1] = -kMaxSlope;
	//}
	//else if (m_SlopeDeg[1] > kMaxSlope) {
	//	m_SlopeDeg[1] = kMaxSlope;
	//}

	//todo :rename
	//やってることは法線の更新
	TranceformOnBoard(D3DXVECTOR3(0.0f, 1.0f, 0.0f), &m_NormalVector);
}

void PhysicsManager::RotTerrain(const D3DXVECTOR3& axis)
{
	D3DXQUATERNION quaternion;
	D3DXQuaternionRotationAxis(&quaternion, &axis, D3DXToRadian(kSlopingDeg));
	D3DXMATRIXA16 tmp;
	D3DXMatrixRotationQuaternion(&tmp, &quaternion);
	*m_pRot_mat = *m_pRot_mat*tmp;
}

D3DXVECTOR3* PhysicsManager::TranceformOnBoard(const D3DXVECTOR3& in, D3DXVECTOR3* out)
{
	return D3DXVec3TransformCoord(out, &in, m_pRot_mat);
}

void PhysicsManager::Initialize()
{
	m_NormalVector = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixIdentity(m_pRot_mat);
	//m_SlopeDeg[0] = 0.0f;
	//m_SlopeDeg[1] = 0.0f;
}