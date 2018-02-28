#include"Sky.h"
#include"ModelManager.h"
#include"DirectGraphics.h"
#include"EffectManager.h"
#include"Lib.h"

void Sky::Update()
{
}

void Sky::DrawPreparation()
{

}

void Sky::Draw()
{
	Lib::GetInstance().TransformWorld(m_Pos);

	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&WorldMatrix);

	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\sky.fbx").Draw();
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}