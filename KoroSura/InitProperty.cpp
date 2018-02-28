#include "InitProperty.h"
#include"Common.h"

InitProperty* InitProperty::m_pInstance = nullptr;

InitProperty::InitProperty()
{
	LoadSlime();
	LoadEnemy();
	LoadGimmick();
	LoadPhysics();
	LoadCamera();
}

InitProperty::~InitProperty()
{
}

void InitProperty::LoadSlime()
{
	m_InitialData.slimeInitialData.colliderOffset.x =
		GetPrivateProfileInt("�X���C��", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.colliderOffset.y =
		GetPrivateProfileInt("�X���C��", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.colliderOffset.z =
		GetPrivateProfileInt("�X���C��", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.modelOffset =
		GetPrivateProfileInt("�X���C��", "ModelOffset", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.radius =
		GetPrivateProfileInt("�X���C��", "���a", 1, MATERIAL_FILENAME);
}

void InitProperty::LoadEnemy()
{
	LoadSpider();
}

void InitProperty::LoadGimmick()
{
	LoadFence();
}

void InitProperty::LoadPhysics()
{
	m_InitialData.gravity = GetPrivateProfileInt("PhysicalVal", "Gravity", 1, PROPERTY_FILENAME) / 100.0f;

	m_InitialData.dynamicCoefficientOfFriction = 
		GetPrivateProfileInt("PhysicalVal", "�����C�W��", 1, PROPERTY_FILENAME) / 100.0f;

	m_InitialData.staticCoefficientOfFriction =
		GetPrivateProfileInt("PhysicalVal", "�Î~���C�W��", 1, PROPERTY_FILENAME) / 100.0f;

	m_InitialData.deg =
		GetPrivateProfileInt("PhysicalVal", "�X����p�x", 1, PROPERTY_FILENAME) / 100.0f;
}

void InitProperty::LoadCamera()
{
	m_InitialData.cameraYPos =
		GetPrivateProfileInt("Camera", "Y", 1, PROPERTY_FILENAME);

	m_InitialData.lookAtPosYOffset =
		GetPrivateProfileInt("Camera", "SlimeYOffset", 1, PROPERTY_FILENAME);

	m_InitialData.cameraDistance=
		GetPrivateProfileInt("Camera", "Distance", 1, PROPERTY_FILENAME);
}

void InitProperty::LoadSpider()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderOffset.x =
		GetPrivateProfileInt("�N��", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderOffset.y =
		GetPrivateProfileInt("�N��", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderOffset.z =
		GetPrivateProfileInt("�N��", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderSize.x =
		GetPrivateProfileInt("�N��", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderSize.y =
		GetPrivateProfileInt("�N��", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderSize.z =
		GetPrivateProfileInt("�N��", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].modelOffset =
		GetPrivateProfileInt("�N��", "ModelOffset", 1, MATERIAL_FILENAME);
}

void InitProperty::LoadFence()
{

}