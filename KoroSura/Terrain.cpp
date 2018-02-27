#include"Terrain.h"
#include"StageInfo.h"
#include"FBX.h"
#include"DirectGraphics.h"
#include"TextureManager.h"
#include"Lib.h"
#include"DirLightSource.h"
#include"ModelManager.h"
#include"PhysicsManager.h"
#include"EffectManager.h"

Terrain::Terrain():
	MaterialBase(D3DXVECTOR3(0.0f,0.0f,0.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f))
{
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
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&WorldMatrix);
	// シェーダーパスの開始.
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\board.fbx").Draw();
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}