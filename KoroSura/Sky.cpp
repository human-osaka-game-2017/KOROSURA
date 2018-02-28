#include"Sky.h"
#include"ModelManager.h"
#include"DirectGraphics.h"
#include"EffectManager.h"
#include"Lib.h"

void Sky::Update()
{
	Lib::GetInstance().TransformWorld(m_Pos);
}

void Sky::DrawPreparation()
{
	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&WorldMatrix);
}

void Sky::Draw()
{
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\sky.fbx").Draw();
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}