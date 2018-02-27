#include"Slime.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"Shader.h"
#include"Effect.h"
#include"DirLightSource.h"
#include"ModelManager.h"
#include"Physics.h"
#include"PhysicsManager.h"

Slime::Slime(D3DXVECTOR3& pos):
	CharacterBase(pos)
{
	FxManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");
	//テクニックハンドルの取得
	//Effectごとにやればいい
	m_Technique = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetTechniqueByName("Basic");
	m_World = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "World");
	

	m_pPhysics = new Physics();
}

Slime::~Slime()
{
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
	
	// 定数の設定
	//Effectごとにやればいい
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_World, &WorldMatrix);

	// シェーダーパスの開始.
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\fence.fbx").Draw();
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
}