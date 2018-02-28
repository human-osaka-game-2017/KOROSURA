#include"MainScene.h"
#include"Lib.h"
#include"StageInfo.h"
#include"Slime.h"
#include"Terrain.h"
#include"Sky.h"
#include"Camera.h"
#include"EffectManager.h"
#include"DirectGraphics.h"
#include"DirLightSource.h"
#include"PhysicsManager.h"

MainScene::MainScene()
{
	EffectManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");

	StageInfo::StageData* pStageData = StageInfo::GetInstance().GetStageData();
	Slime*	pSlime		= new Slime(pStageData->slimeData.pos, D3DXVECTOR3(0.0f, 1.0f, 0.0f), pStageData->slimeData.level);
	Sky* pSky			= new Sky();
	Terrain* pTerrain	= new Terrain();
	m_pCamera			= new Camera(pSlime->GetPos());

	m_PtrMaterials.push_back(pSlime);
	m_PtrMaterials.push_back(pSky);
	m_PtrMaterials.push_back(pTerrain);
}

MainScene::~MainScene()
{
	for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
		delete *ite;
	}

	EffectManager::GetpInstance().ReleaseEffect("Shader\\BasicShader.fx");
}

SceneBase::SCENE_ID MainScene::Update()
{
	SceneBase::SCENE_ID retSceneId = SCENE_ID::MAIN;

	Lib::GetInstance().UpdateKey();
	Lib::GetInstance().UpdateMouse();

	DirLightSource::GetpInstance().Update();

	PhysicsManager::GetInstance().Update();

	for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
		(*ite)->Update();
	}

	m_pCamera->Update();

	return retSceneId;
}

void MainScene::Draw()
{
	Lib::GetInstance().StartRender();

	for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
		(*ite)->DrawPreparation();
	}

	D3DXMATRIX ViewMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	D3DXMATRIX ProjMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);

	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetViewMatrix(&ViewMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetProjMatrix(&ProjMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetLightVector();

	for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
		(*ite)->Draw();
	}

	Lib::GetInstance().EndRender();
}
