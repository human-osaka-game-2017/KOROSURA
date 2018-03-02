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
		GetPrivateProfileInt("スライム", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.colliderOffset.y =
		GetPrivateProfileInt("スライム", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.colliderOffset.z =
		GetPrivateProfileInt("スライム", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.modelOffset =
		GetPrivateProfileInt("スライム", "ModelOffset", 1, MATERIAL_FILENAME);

	m_InitialData.slimeInitialData.radius =
		GetPrivateProfileInt("スライム", "半径", 1, MATERIAL_FILENAME);
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
		GetPrivateProfileInt("PhysicalVal", "動摩擦係数", 1, PROPERTY_FILENAME) / 100.0f;

	m_InitialData.staticCoefficientOfFriction =
		GetPrivateProfileInt("PhysicalVal", "静止摩擦係数", 1, PROPERTY_FILENAME) / 100.0f;

	m_InitialData.deg =
		GetPrivateProfileInt("PhysicalVal", "傾ける角度", 1, PROPERTY_FILENAME) / 100.0f;
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
		GetPrivateProfileInt("キノコ", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.y =
		GetPrivateProfileInt("キノコ", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.z =
		GetPrivateProfileInt("キノコ", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.x =
		GetPrivateProfileInt("キノコ", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.y =
		GetPrivateProfileInt("キノコ", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.z =
		GetPrivateProfileInt("キノコ", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].modelOffset =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].modelOffset =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].modelOffset =
		GetPrivateProfileInt("キノコ", "ModelOffset", 1, MATERIAL_FILENAME);
}

void InitProperty::LoadGoblin()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.x =
		GetPrivateProfileInt("ゴブリン", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.y =
		GetPrivateProfileInt("ゴブリン", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.z =
		GetPrivateProfileInt("ゴブリン", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.x =
		GetPrivateProfileInt("ゴブリン", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.y =
		GetPrivateProfileInt("ゴブリン", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.z =
		GetPrivateProfileInt("ゴブリン", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].modelOffset =
		GetPrivateProfileInt("ゴブリン", "ModelOffset", 1, MATERIAL_FILENAME);
}
void InitProperty::LoadTrent()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.x =
		GetPrivateProfileInt("トレント", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.y =
		GetPrivateProfileInt("トレント", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.z =
		GetPrivateProfileInt("トレント", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.x =
		GetPrivateProfileInt("トレント", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.y =
		GetPrivateProfileInt("トレント", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.z =
		GetPrivateProfileInt("トレント", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].modelOffset =
		GetPrivateProfileInt("トレント", "ModelOffset", 1, MATERIAL_FILENAME);
}
void InitProperty::LoadCerberus()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.x =
		GetPrivateProfileInt("ケロべロス", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.y =
		GetPrivateProfileInt("ケロべロス", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.z =
		GetPrivateProfileInt("ケロべロス", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.x =
		GetPrivateProfileInt("ケロべロス", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.y =
		GetPrivateProfileInt("ケロべロス", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.z =
		GetPrivateProfileInt("ケロべロス", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].modelOffset =
		GetPrivateProfileInt("ケロべロス", "ModelOffset", 1, MATERIAL_FILENAME);
}

void InitProperty::LoadFence()
{

}