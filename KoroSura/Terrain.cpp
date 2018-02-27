#include"Terrain.h"
#include"StageInfo.h"
#include"FBX.h"
#include"DirectGraphics.h"
#include"TextureManager.h"
#include"Lib.h"
#include"Shader.h"
#include"Effect.h"
#include"DirLightSource.h"
#include"ModelManager.h"
#include"PhysicsManager.h"

Terrain::Terrain():
	MaterialBase(D3DXVECTOR3(0.0f,0.0f,0.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f))
{
	FxManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");
	//テクニックハンドルの取得
	//Effectごとにやればいい
	m_Technique = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetTechniqueByName("Basic");
	m_World = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "World");
}

Terrain::~Terrain() 
{
	delete[] m_TerrainData;
}

void Terrain::Draw()
{
	float* slopeDeg = PhysicsManager::GetInstance().GetSlopeDeg();

	Lib::GetInstance().TransformWorld(m_Pos,0.0f, slopeDeg[0], slopeDeg[1]);

	//変換行列の取得
	//Effectごとにやればいい
	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	// 定数の設定
	//Effectごとにやればいい
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_World, &WorldMatrix);
	// シェーダーパスの開始.
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\board.fbx").Draw();
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
}