#include"GimmickBase.h"
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

GimmickBase::GimmickBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, GIMMICK_KIND kind, float angleDeg) :
	MaterialBase(pos, normalVec),
	kKind(kind),
	kInitPos(pos),
	m_Angle_deg(angleDeg)
{
	m_Pos.y += InitProperty::GetInstance().GetInitialData().gimmickInitialData[static_cast<int>(kind)].modelOffset;
	m_OBB.SetPos(InitProperty::GetInstance().GetInitialData().gimmickInitialData[static_cast<int>(kind)].colliderOffset + m_Pos);

	m_OBB.SetDirect(0, D3DXVECTOR3(cos(D3DXToRadian(angleDeg)), 0.0f, sin(D3DXToRadian(angleDeg))));
	m_OBB.SetDirect(1, D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	m_OBB.SetDirect(2, D3DXVECTOR3(cos(D3DXToRadian(angleDeg + 90.0f)), 0.0f, sin(D3DXToRadian(angleDeg + 90.0f))));
	//m_OBB.SetDirect(0, D3DXVECTOR3(1.0f, 0.0f, 0.0f));
	//m_OBB.SetDirect(1, D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	//m_OBB.SetDirect(2, D3DXVECTOR3(0.0f, 0.0f, 1.0f));
	m_OBB.SetLength(0, InitProperty::GetInstance().GetInitialData().gimmickInitialData[static_cast<int>(kind)].colliderSize.x);
	m_OBB.SetLength(1, InitProperty::GetInstance().GetInitialData().gimmickInitialData[static_cast<int>(kind)].colliderSize.y);
	m_OBB.SetLength(2, InitProperty::GetInstance().GetInitialData().gimmickInitialData[static_cast<int>(kind)].colliderSize.z);

	m_pCollider = new BoxCollider("GimmickBase", this, &m_OBB, std::bind(&GimmickBase::Collided, this, std::placeholders::_1),
		CATEGORY_BITS_ENEMY, CATEGORY_BITS_SLIME);

	ColliderManager::GetInstance().Register(m_pCollider, 0);
}

GimmickBase::~GimmickBase()
{
	ColliderManager::GetInstance().Remove(m_pCollider);
	delete m_pCollider;
}

void GimmickBase::Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects)
{

}

void GimmickBase::Update()
{
	PhysicsManager::GetInstance().TranceformOnBoard(kInitPos, &m_Pos);
	m_Pos.y += InitProperty::GetInstance().GetInitialData().gimmickInitialData[static_cast<int>(kKind)].modelOffset;
	m_OBB.SetPos(InitProperty::GetInstance().GetInitialData().gimmickInitialData[static_cast<int>(kKind)].colliderOffset + m_Pos);
}

void GimmickBase::Draw()
{
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
	D3DXMatrixMultiply(&matWorld, &matWorld, PhysicsManager::GetInstance().GetRotMatrix());

	//平行移動
	D3DXMatrixTranslation(&matPosition, m_Pos.x, m_Pos.y, m_Pos.z);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

	//レンダリング仕様の登録
	(*DirectGraphics::GetInstance().GetDevice())->SetTransform(D3DTS_WORLD, &matWorld);

	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&matWorld);

	// シェーダーパスの開始.
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	switch (kKind) {
	case GimmickBase::GIMMICK_KIND::FENCE:
		ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\fence.fbx").Draw();
		break;
	}

	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}