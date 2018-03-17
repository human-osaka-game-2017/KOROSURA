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
		static_cast<int>(GetPrivateProfileInt("スライム", "ColliderOffsetX", 1, MATERIAL_FILENAME));

	m_InitialData.slimeInitialData.colliderOffset.y =
		static_cast<int>(GetPrivateProfileInt("スライム", "ColliderOffsetY", 1, MATERIAL_FILENAME));

	m_InitialData.slimeInitialData.colliderOffset.z =
		static_cast<int>(GetPrivateProfileInt("スライム", "ColliderOffsetZ", 1, MATERIAL_FILENAME));

	m_InitialData.slimeInitialData.modelOffset =
		static_cast<int>(GetPrivateProfileInt("スライム", "ModelOffset", 1, MATERIAL_FILENAME));

	m_InitialData.slimeInitialData.radius =
		static_cast<int>(GetPrivateProfileInt("スライム", "半径", 1, MATERIAL_FILENAME));
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
	m_InitialData.gravity = (GetPrivateProfileInt("PhysicalVal", "Gravity", 1, PROPERTY_FILENAME) / 100.0f);

	m_InitialData.dynamicCoefficientOfFriction = 
		(GetPrivateProfileInt("PhysicalVal", "動摩擦係数", 1, PROPERTY_FILENAME) / 100.0f);

	m_InitialData.staticCoefficientOfFriction =
		(GetPrivateProfileInt("PhysicalVal", "静止摩擦係数", 1, PROPERTY_FILENAME) / 100.0f);

	m_InitialData.deg =
		(GetPrivateProfileInt("PhysicalVal", "傾ける角度", 1, PROPERTY_FILENAME) / 100.0f);
}

void InitProperty::LoadCamera()
{
	m_InitialData.cameraYPos =
		static_cast<int>(GetPrivateProfileInt("Camera", "Y", 1, PROPERTY_FILENAME));

	m_InitialData.lookAtPosYOffset =
		static_cast<int>(GetPrivateProfileInt("Camera", "SlimeYOffset", 1, PROPERTY_FILENAME));

	m_InitialData.cameraDistance=
		static_cast<int>(GetPrivateProfileInt("Camera", "Distance", 1, PROPERTY_FILENAME));
}

void InitProperty::LoadMushroom()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.x =
		static_cast<int>(GetPrivateProfileInt("キノコ", "ColliderOffsetX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.y =
		static_cast<int>(GetPrivateProfileInt("キノコ", "ColliderOffsetY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderOffset.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderOffset.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderOffset.z =
		static_cast<int>(GetPrivateProfileInt("キノコ", "ColliderOffsetZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.x =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.x =
		static_cast<int>(GetPrivateProfileInt("キノコ", "ColliderSizeX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.y =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.y =
		static_cast<int>(GetPrivateProfileInt("キノコ", "ColliderSizeY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].colliderSize.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].colliderSize.z =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].colliderSize.z =
		static_cast<int>(GetPrivateProfileInt("キノコ", "ColliderSizeZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_RED)].modelOffset =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_BLUE)].modelOffset =
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE)].modelOffset =
		static_cast<int>(GetPrivateProfileInt("キノコ", "ModelOffset", 1, MATERIAL_FILENAME));
}

void InitProperty::LoadGoblin()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.x =
		static_cast<int>(GetPrivateProfileInt("ゴブリン", "ColliderOffsetX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.y =
		static_cast<int>(GetPrivateProfileInt("ゴブリン", "ColliderOffsetY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderOffset.z =
		static_cast<int>(GetPrivateProfileInt("ゴブリン", "ColliderOffsetZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.x =
		static_cast<int>(GetPrivateProfileInt("ゴブリン", "ColliderSizeX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.y =
		static_cast<int>(GetPrivateProfileInt("ゴブリン", "ColliderSizeY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].colliderSize.z =
		static_cast<int>(GetPrivateProfileInt("ゴブリン", "ColliderSizeZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::GOBLIN_PURPLE)].modelOffset =
		static_cast<int>(GetPrivateProfileInt("ゴブリン", "ModelOffset", 1, MATERIAL_FILENAME));
}
void InitProperty::LoadTrent()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.x =
		static_cast<int>(GetPrivateProfileInt("トレント", "ColliderOffsetX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.y =
		static_cast<int>(GetPrivateProfileInt("トレント", "ColliderOffsetY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderOffset.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderOffset.z =
		static_cast<int>(GetPrivateProfileInt("トレント", "ColliderOffsetZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.x =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.x =
		static_cast<int>(GetPrivateProfileInt("トレント", "ColliderSizeX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.y =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.y =
		static_cast<int>(GetPrivateProfileInt("トレント", "ColliderSizeY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].colliderSize.z =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].colliderSize.z =
		static_cast<int>(GetPrivateProfileInt("トレント", "ColliderSizeZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_GREEN)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_YELLOW)].modelOffset =
		m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::TRENT_PINK)].modelOffset =
		static_cast<int>(GetPrivateProfileInt("トレント", "ModelOffset", 1, MATERIAL_FILENAME));
}
void InitProperty::LoadCerberus()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.x =
		static_cast<int>(GetPrivateProfileInt("ケロべロス", "ColliderOffsetX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.y =
		static_cast<int>(GetPrivateProfileInt("ケロべロス", "ColliderOffsetY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderOffset.z =
		static_cast<int>(GetPrivateProfileInt("ケロべロス", "ColliderOffsetZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.x =
		static_cast<int>(GetPrivateProfileInt("ケロべロス", "ColliderSizeX", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.y =
		static_cast<int>(GetPrivateProfileInt("ケロべロス", "ColliderSizeY", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].colliderSize.z =
		static_cast<int>(GetPrivateProfileInt("ケロべロス", "ColliderSizeZ", 1, MATERIAL_FILENAME));

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::CERBERUS)].modelOffset =
		static_cast<int>(GetPrivateProfileInt("ケロべロス", "ModelOffset", 1, MATERIAL_FILENAME));
}

void InitProperty::LoadFence()
{
	m_InitialData.gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::FENCE)].colliderOffset.x =
		static_cast<int>(GetPrivateProfileInt("フェンス", "ColliderOffsetX", 1, MATERIAL_FILENAME));

	m_InitialData.gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::FENCE)].colliderOffset.y =
		static_cast<int>(GetPrivateProfileInt("フェンス", "ColliderOffsetY", 1, MATERIAL_FILENAME));

	m_InitialData.gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::FENCE)].colliderOffset.z =
		static_cast<int>(GetPrivateProfileInt("フェンス", "ColliderOffsetZ", 1, MATERIAL_FILENAME));

	m_InitialData.gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::FENCE)].colliderSize.x =
		static_cast<int>(GetPrivateProfileInt("フェンス", "ColliderSizeX", 1, MATERIAL_FILENAME));

	m_InitialData.gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::FENCE)].colliderSize.y =
		static_cast<int>(GetPrivateProfileInt("フェンス", "ColliderSizeY", 1, MATERIAL_FILENAME));

	m_InitialData.gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::FENCE)].colliderSize.z =
		static_cast<int>(GetPrivateProfileInt("フェンス", "ColliderSizeZ", 1, MATERIAL_FILENAME));

	m_InitialData.gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::FENCE)].modelOffset =
		static_cast<int>(GetPrivateProfileInt("フェンス", "ModelOffset", 1, MATERIAL_FILENAME));
}