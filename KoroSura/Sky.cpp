#include"Sky.h"
#include"Shader.h"
#include"ModelManager.h"
#include"DirectGraphics.h"
#include"Effect.h"

void Sky::Draw()
{
	D3DXMATRIX WorldMatrix;
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_World, &WorldMatrix);

	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\sky.fbx").Draw();
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
}