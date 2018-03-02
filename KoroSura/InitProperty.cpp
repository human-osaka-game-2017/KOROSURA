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
	LoadMushroom();
	LoadGoblin();
	LoadTrent();
	LoadCerberus();
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

void InitProperty::LoadMushroom()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.x =
		GetPrivateProfileInt("�L�m�R", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.y =
		GetPrivateProfileInt("�L�m�R", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.z =
		GetPrivateProfileInt("�L�m�R", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.x =
		GetPrivateProfileInt("�L�m�R", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.y =
		GetPrivateProfileInt("�L�m�R", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.z =
		GetPrivateProfileInt("�L�m�R", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].modelOffset =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].modelOffset =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].modelOffset =
		GetPrivateProfileInt("�L�m�R", "ModelOffset", 1, MATERIAL_FILENAME);
}

void InitProperty::LoadGoblin()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.x =
		GetPrivateProfileInt("�S�u����", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.y =
		GetPrivateProfileInt("�S�u����", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.z =
		GetPrivateProfileInt("�S�u����", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.x =
		GetPrivateProfileInt("�S�u����", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.y =
		GetPrivateProfileInt("�S�u����", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.z =
		GetPrivateProfileInt("�S�u����", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].modelOffset =
		GetPrivateProfileInt("�S�u����", "ModelOffset", 1, MATERIAL_FILENAME);
}
void InitProperty::LoadTrent()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.x =
		GetPrivateProfileInt("�g�����g", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.y =
		GetPrivateProfileInt("�g�����g", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.z =
		GetPrivateProfileInt("�g�����g", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.x =
		GetPrivateProfileInt("�g�����g", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.y =
		GetPrivateProfileInt("�g�����g", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.z =
		GetPrivateProfileInt("�g�����g", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].modelOffset =
		GetPrivateProfileInt("�g�����g", "ModelOffset", 1, MATERIAL_FILENAME);
}
void InitProperty::LoadCerberus()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.x =
		GetPrivateProfileInt("�P���׃��X", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.y =
		GetPrivateProfileInt("�P���׃��X", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.z =
		GetPrivateProfileInt("�P���׃��X", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.x =
		GetPrivateProfileInt("�P���׃��X", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.y =
		GetPrivateProfileInt("�P���׃��X", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.z =
		GetPrivateProfileInt("�P���׃��X", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].modelOffset =
		GetPrivateProfileInt("�P���׃��X", "ModelOffset", 1, MATERIAL_FILENAME);
}

void InitProperty::LoadFence()
{

}