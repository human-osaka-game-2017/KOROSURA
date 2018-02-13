#include "InitProperty.h"
#include"Common.h"

InitProperty::InitProperty()
{
	LoadSlime();
	LoadEnemy();
	LoadGimmick();
	LoadPhysics();
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
	LoadSpider();
}

void InitProperty::LoadGimmick()
{
	LoadFence();
}
void InitProperty::LoadPhysics()
{
	m_InitialData.gravity = GetPrivateProfileInt("PhysicalVal", "Gravity", 1, PROPERTY_FILENAME) / 100.0f;

	m_InitialData.coefficientOfFriction = 
		GetPrivateProfileInt("PhysicalVal", "摩擦係数", 1, PROPERTY_FILENAME) / 100.0f;
}

void InitProperty::LoadSpider()
{
	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderOffset.x =
		GetPrivateProfileInt("クモ", "ColliderOffsetX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderOffset.y =
		GetPrivateProfileInt("クモ", "ColliderOffsetY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderOffset.z =
		GetPrivateProfileInt("クモ", "ColliderOffsetZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderSize.x =
		GetPrivateProfileInt("クモ", "ColliderSizeX", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderSize.y =
		GetPrivateProfileInt("クモ", "ColliderSizeY", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].colliderSize.z =
		GetPrivateProfileInt("クモ", "ColliderSizeZ", 1, MATERIAL_FILENAME);

	m_InitialData.enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::SPIDER)].modelOffset =
		GetPrivateProfileInt("クモ", "ModelOffset", 1, MATERIAL_FILENAME);
}

void InitProperty::LoadFence()
{

}