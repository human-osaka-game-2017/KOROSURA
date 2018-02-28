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
	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::W) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[0] += kSlopingDeg;
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::A) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::LEFT) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[1] += kSlopingDeg;
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::S) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::DOWN) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[0] -= kSlopingDeg;
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::D) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::RIGHT) == Utility::BUTTON_STATE::ON) {
		m_SlopeDeg[1] -= kSlopingDeg;
	}

	//âÒì]ópçsóÒ
	Matrix mat(3, 1,
		0.0f,
		1.0f,
		0.0f);

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
	m_NormalVector.x = mat.m_Mat[0][0];
	m_NormalVector.y = mat.m_Mat[1][0];
	m_NormalVector.z = mat.m_Mat[2][0];

	OutputDebugString("x=");
	Utility::OutputDebug_Number(m_NormalVector.x);
	OutputDebugString("y=");
	Utility::OutputDebug_Number(m_NormalVector.y);
	OutputDebugString("z=");
	Utility::OutputDebug_Number(m_NormalVector.z);
}