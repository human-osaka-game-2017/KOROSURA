#include"Slime.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"Shader.h"
#include"Effect.h"
#include"DirLightSource.h"
#include"ModelManager.h"

Slime::Slime(D3DXVECTOR3& pos):
	CharacterBase(pos)
{
	FxManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");
	//テクニックハンドルの取得
	//Effectごとにやればいい
	m_Technique = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetTechniqueByName("Basic");
	m_World = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "World");
	m_View = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "View");
	m_Proj = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Proj");
	m_Light = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Light");
}

Slime::~Slime()
{
}

void Slime::Update()
{
	Lib::GetInstance().TransformWorld(m_Pos);
}

void Slime::Draw()
{
	//変換行列の取得
	//Effectごとにやればいい
	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	D3DXMATRIX ViewMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	D3DXMATRIX ProjMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);
	// 定数の設定
	//Effectごとにやればいい
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_World, &WorldMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_View, &ViewMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_Proj, &ProjMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetVector(m_Light, &DirLightSource::GetpInstance().GetlightDir());
	// シェーダーパスの開始.
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\fence.fbx").Draw();
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
}