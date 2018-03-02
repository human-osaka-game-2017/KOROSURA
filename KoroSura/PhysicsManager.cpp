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
	m_SlopeDeg[0] = 0.0f;
	m_SlopeDeg[1] = 0.0f;
}

PhysicsManager::~PhysicsManager()
{
}


void PhysicsManager::Update()
{
	D3DXVECTOR2 cameraXZ = D3DXVECTOR2(m_CameraVec.x, m_CameraVec.z);

	//カメラのy軸中心の回転角度
	float deg = Utility::MyAtanDeg(cameraXZ);
	float rad = D3DXToRadian(deg);

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::W) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::ON) {
		if (m_SlopeDeg[0] < 65.0f) {
			m_SlopeDeg[0] += kSlopingDeg;
		}
		//m_SlopeDeg[0] -= kSlopingDeg*sin(rad);
		//m_SlopeDeg[1] -= kSlopingDeg*cos(rad);
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::A) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::LEFT) == Utility::BUTTON_STATE::ON) {
		if (m_SlopeDeg[1] < 65.0f) {
			m_SlopeDeg[1] += kSlopingDeg;
		}
		//m_SlopeDeg[0] += kSlopingDeg*cos(rad);
		//m_SlopeDeg[1] += kSlopingDeg*sin(rad);
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::S) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::DOWN) == Utility::BUTTON_STATE::ON) {
		if (m_SlopeDeg[0] > -65.0f) {
			m_SlopeDeg[0] -= kSlopingDeg;
		}
		//m_SlopeDeg[0] += kSlopingDeg*sin(rad);
		//m_SlopeDeg[1] += kSlopingDeg*cos(rad);
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::D) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::RIGHT) == Utility::BUTTON_STATE::ON) {
		if (m_SlopeDeg[1] > -65.0f) {
			m_SlopeDeg[1] -= kSlopingDeg;
		}
		//m_SlopeDeg[0] -= kSlopingDeg*cos(rad);
		//m_SlopeDeg[1] -= kSlopingDeg*sin(rad);
	}

	//todo :rename
	//やってることは法線の更新
	TranceformOnBoard(D3DXVECTOR3(0.0f, 1.0f, 0.0f), &m_NormalVector);
}

D3DXVECTOR3* PhysicsManager::TranceformOnBoard(const D3DXVECTOR3& in, D3DXVECTOR3* out)
{
	//回転用行列
	Matrix mat(3, 1,
		in.x,
		in.y,
		in.z);

	Matrix matRotation;
	Matrix tmp;

	matRotation.m_Row = 3;
	matRotation.m_Column = 3;
	matRotation.Initialize();

	Utility::GetRotationXMatrix(&tmp, m_SlopeDeg[0]);
	matRotation *= tmp;
	Utility::GetRotationZMatrix(&tmp, m_SlopeDeg[1]);
	matRotation *= tmp;

	mat = matRotation * mat;
	out->x = mat.m_Mat[0][0];
	out->y = mat.m_Mat[1][0];
	out->z = mat.m_Mat[2][0];
	return out;
}