#include"EnemyBase.h"
#include"InitProperty.h"
#include"Physics.h"
#include"StageInfo.h"
#include"ColliderManager.h"
#include"BoxCollider.h"
#include"Common.h"
#include"ModelManager.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"EffectManager.h"
#include"PhysicsManager.h"

EnemyBase::EnemyBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level, ENEMY_KIND kind, float angleDeg) :
	CharacterBase(pos, normalVec, level),
	kKind(kind),
	kInitPos(pos)
{
	m_Pos.y += InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].modelOffset;
	m_OBB.SetPos(InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderOffset + m_Pos);

	m_OBB.SetDirect(0, D3DXVECTOR3(cos(D3DXToRadian(angleDeg)), 0.0f, sin(D3DXToRadian(angleDeg))));
	m_OBB.SetDirect(1, D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	m_OBB.SetDirect(2, D3DXVECTOR3(cos(D3DXToRadian(90.0f - angleDeg)), 0.0f, sin(D3DXToRadian(90.0f - angleDeg))));
	m_OBB.SetLength(0,InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderSize.x);
	m_OBB.SetLength(1,InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderSize.y);
	m_OBB.SetLength(2,InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderSize.z);

	m_pCollider = new BoxCollider("EnemyBase", this, &m_OBB, std::bind(&EnemyBase::Collided, this, std::placeholders::_1),
		CATEGORY_BITS_ENEMY, CATEGORY_BITS_SLIME);

	ColliderManager::GetInstance().Register(m_pCollider, 0);
}

void EnemyBase::Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects)
{

}

void EnemyBase::Update()
{
	PhysicsManager::GetInstance().TranceformOnBoard(kInitPos, &m_Pos);
}

void EnemyBase::Draw()
{
	Lib::GetInstance().TransformWorld(m_Pos);

	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&WorldMatrix);

	// シェーダーパスの開始.
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	switch (kKind) {
	case EnemyBase::ENEMY_KIND::SLIME:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\slime.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::MUSHROOM_RED:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\mushroom_r.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::MUSHROOM_BLUE:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\mushroom_b.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::MUSHROOM_PURPLE:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\mushroom_p.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::GOBLIN:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\goblin.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::GOBLIN_PURPLE:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\goblin_p.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::TRENT_GREEN:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\treant_mg.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::TRENT_YELLOW:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\treant_mp.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::TRENT_PINK:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\treant_my.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::CERBERUS:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\Cerberus_og2.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::TIGER:
		//ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\slime.fbx").Draw();
		break;

	case EnemyBase::ENEMY_KIND::MINOTAUR:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\minotaur.fbx").Draw();
		break;
	}
	
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
	
}