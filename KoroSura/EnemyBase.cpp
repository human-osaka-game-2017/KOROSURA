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

EnemyBase::EnemyBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level, ENEMY_KIND kind, float angleDeg ,bool isBoss) :
	CharacterBase(pos, normalVec, level),
	kKind(kind),
	kInitPos(pos),
	m_IsBoss(isBoss),
	m_Angle_deg(angleDeg)
{
	m_Pos.y += InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].modelOffset;
	m_OBB.SetPos(InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderOffset + m_Pos);

	m_OBB.SetDirect(0, D3DXVECTOR3(cos(D3DXToRadian(angleDeg)), 0.0f, sin(D3DXToRadian(angleDeg))));
	m_OBB.SetDirect(1, D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	m_OBB.SetDirect(2, D3DXVECTOR3(cos(D3DXToRadian(angleDeg + 90.0f)), 0.0f, sin(D3DXToRadian(angleDeg + 90.0f))));
	//m_OBB.SetDirect(0, D3DXVECTOR3(1.0f, 0.0f, 0.0f));
	//m_OBB.SetDirect(1, D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	//m_OBB.SetDirect(2, D3DXVECTOR3(0.0f, 0.0f, 1.0f));
	m_OBB.SetLength(0,InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderSize.x);
	m_OBB.SetLength(1,InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderSize.y);
	m_OBB.SetLength(2,InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kind)].colliderSize.z);

	m_pCollider = new BoxCollider("EnemyBase", this, &m_OBB, std::bind(&EnemyBase::Collided, this, std::placeholders::_1),
		CATEGORY_BITS_ENEMY, CATEGORY_BITS_SLIME);

	ColliderManager::GetInstance().Register(m_pCollider, 0);
}

EnemyBase::~EnemyBase()
{
	ColliderManager::GetInstance().Remove(m_pCollider);
	delete m_pCollider;
}

void EnemyBase::Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects)
{

}

void EnemyBase::Update()
{
	PhysicsManager::GetInstance().TranceformOnBoard(kInitPos, &m_Pos);
	m_Pos.y += InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kKind)].modelOffset;
	m_OBB.SetPos(InitProperty::GetInstance().GetInitialData().enemyInitialData[static_cast<int>(kKind)].colliderOffset + m_Pos);
}

void EnemyBase::Draw()
{
	const float* slope_deg = PhysicsManager::GetInstance().GetSlopeDeg();

	//最終的なワールドトランスフォーム行列
	D3DXMATRIXA16 matWorld;
	//平行移動用行列
	D3DXMATRIXA16 matPosition;
	//回転用行列
	D3DXMATRIXA16 matRotation;

	//行列の初期化
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matRotation);

	//ワールドトランスフォーム（絶対座標変換）
	//回転
	D3DXMatrixRotationY(&matRotation, D3DXToRadian(m_Angle_deg));
	D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);
	D3DXMatrixRotationX(&matRotation, D3DXToRadian(slope_deg[0]));
	D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);
	D3DXMatrixRotationZ(&matRotation, D3DXToRadian(slope_deg[1]));
	D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);

	//平行移動
	D3DXMatrixTranslation(&matPosition, m_Pos.x, m_Pos.y, m_Pos.z);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

	//レンダリング仕様の登録
	(*DirectGraphics::GetInstance().GetDevice())->SetTransform(D3DTS_WORLD, &matWorld);

	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&matWorld);

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