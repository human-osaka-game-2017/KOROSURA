#include"Slime.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"ModelManager.h"
#include"Physics.h"
#include"PhysicsManager.h"
#include"EffectManager.h"

Slime::Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level):
	CharacterBase(pos, normalVec, level)
{
	m_pPhysics = new Physics();
}

Slime::~Slime()
{
	delete m_pPhysics;
}

void Slime::Update()
{
	D3DXVECTOR3 rollVec;
	if (PhysicsManager::GetInstance().CanRoll()) {
		m_pPhysics->GetRollVec(&rollVec, m_Pos);
		rollVec *= m_pPhysics->GetRollVelocity();
		m_Pos += rollVec;
	}

	Lib::GetInstance().TransformWorld(m_Pos);
}

void Slime::Draw()
{
	//変換行列の取得
	//Effectごとにやればいい
	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	//Effectごとにやればいい
	D3DXMATRIX ViewMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	D3DXMATRIX ProjMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);

	// 定数の設定
	//Effectごとにやればいい
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&WorldMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetViewMatrix(&ViewMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetProjMatrix(&ProjMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetLightVector();

	// シェーダーパスの開始.
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\sky.fbx").Draw();
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}