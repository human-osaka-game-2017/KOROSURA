#include"PhysicsManager.h"
#include"InitProperty.h"
#include"Matrix.h"
#include"Lib.h"

PhysicsManager* PhysicsManager::m_pInstance = nullptr;

PhysicsManager::PhysicsManager():
	kGravity(InitProperty::GetInstance().GetInitialData().gravity),
	kSlopingDeg(InitProperty::GetInstance().GetInitialData().deg),
	kDynamicCoefficientOfFriction(InitProperty::GetInstance().GetInitialData().dynamicCoefficientOfFriction),
	kStaticCoefficientOfFriction(InitProperty::GetInstance().GetInitialData().staticCoefficientOfFriction)
{
	m_Slope[0] = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	m_Slope[1] = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	CalNormalVec();
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::Update()
{
	float radX = 0.0f;
	float radZ = 0.0f;

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::W) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::ON) {

		radX += D3DXToRadian((m_CameraVec.x * kSlopingDeg) / (m_CameraVec.x + m_CameraVec.z));
		radZ += D3DXToRadian((m_CameraVec.z * kSlopingDeg) / (m_CameraVec.x + m_CameraVec.z));
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::A) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::LEFT) == Utility::BUTTON_STATE::ON) {

		radX += D3DXToRadian((m_CameraVec.x * kSlopingDeg) / (m_CameraVec.x + -m_CameraVec.z));
		radZ += D3DXToRadian((-m_CameraVec.z * kSlopingDeg) / (m_CameraVec.x + -m_CameraVec.z));
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::S) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::DOWN) == Utility::BUTTON_STATE::ON) {

		radX += D3DXToRadian((-m_CameraVec.x * kSlopingDeg) / (-m_CameraVec.x + m_CameraVec.z));
		radZ += D3DXToRadian((m_CameraVec.z * kSlopingDeg) / (-m_CameraVec.x + m_CameraVec.z));
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::D) == Utility::BUTTON_STATE::ON ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::RIGHT) == Utility::BUTTON_STATE::ON) {

		radX += D3DXToRadian((-m_CameraVec.x * kSlopingDeg) / (-m_CameraVec.x + -m_CameraVec.z));
		radZ += D3DXToRadian((-m_CameraVec.z * kSlopingDeg) / (-m_CameraVec.x + -m_CameraVec.z));
	}

	D3DXVECTOR3 tmp[2] = { m_Slope[0] ,m_Slope[1] };

	m_Slope[0].x += tmp[0].x * cos(radX)
		- tmp[0].y * sin(radX);
	m_Slope[0].y += tmp[0].x * sin(radX)
		+ tmp[0].y * cos(radX);

	m_Slope[1].z += tmp[1].z * cos(radZ)
		- tmp[1].y * sin(radZ);
	m_Slope[1].y += tmp[1].z * sin(radZ)
		+ tmp[1].y * cos(radZ);

	CalNormalVec();
}

void PhysicsManager::CalNormalVec()
{
	//ñ@ê¸åvéZ
	m_NormalVector.x = m_Slope[0].y * m_Slope[1].z - m_Slope[0].z * m_Slope[1].y;
	m_NormalVector.y = m_Slope[0].z * m_Slope[1].x - m_Slope[0].x * m_Slope[1].z;
	m_NormalVector.z = m_Slope[0].x * m_Slope[1].y - m_Slope[0].y * m_Slope[1].x;
}