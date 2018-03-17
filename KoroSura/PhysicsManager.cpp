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
	const float rad = D3DXToRadian(deg);

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::W) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[0] += kSlopingDeg*sin(rad);
		m_SlopeDeg[1] -= kSlopingDeg*cos(rad);
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::A) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::LEFT) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[0] += kSlopingDeg*sin(rad + D3DX_PI / 2);
		m_SlopeDeg[1] -= kSlopingDeg*cos(rad + D3DX_PI / 2);
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::S) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::DOWN) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[0] -= kSlopingDeg*sin(rad);
		m_SlopeDeg[1] += kSlopingDeg*cos(rad);
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::D) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::RIGHT) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[0] -= kSlopingDeg*sin(rad + D3DX_PI / 2);
		m_SlopeDeg[1] += kSlopingDeg*cos(rad + D3DX_PI / 2);
	}

	//上限
	if (m_SlopeDeg[0] < -kMaxSlope) {
		m_SlopeDeg[0] = -kMaxSlope;
	}
	else if (m_SlopeDeg[0] > kMaxSlope) {
		m_SlopeDeg[0] = kMaxSlope;
	}
	if (m_SlopeDeg[1] < -kMaxSlope) {
		m_SlopeDeg[1] = -kMaxSlope;
	}
	else if (m_SlopeDeg[1] > kMaxSlope) {
		m_SlopeDeg[1] = kMaxSlope;
	}

	//todo :rename
	//やってることは法線の更新
	TranceformOnBoard(D3DXVECTOR3(0.0f, 1.0f, 0.0f), &m_NormalVector);
}

D3DXVECTOR3* PhysicsManager::TranceformOnBoard(const D3DXVECTOR3& in, D3DXVECTOR3* out)
{
	Matrix matRotation;

	{
		matRotation.m_Row = 3;
		matRotation.m_Column = 3;
		matRotation.Initialize();

		{
			Matrix tmp;

			Utility::GetRotationXMatrix(&tmp, m_SlopeDeg[0]);
			matRotation *= tmp;
		}
		{
			Matrix tmp;

			Utility::GetRotationZMatrix(&tmp, m_SlopeDeg[1]);
			matRotation *= tmp;
		}
	}

	//回転用行列
	Matrix mat(3, 1,
		in.x,
		in.y,
		in.z);

	Matrix	retMat = matRotation * mat;

	//出力先にコメント
	{
		out->x = retMat.m_Mat[0][0];
		out->y = retMat.m_Mat[1][0];
		out->z = retMat.m_Mat[2][0];
	}

	return out;
}

void PhysicsManager::Initialize()
{
	m_NormalVector = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_SlopeDeg[0] = 0.0f;
	m_SlopeDeg[1] = 0.0f;
}