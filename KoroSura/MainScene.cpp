#include"MainScene.h"
#include"Lib.h"
#include"StageInfo.h"
#include"Slime.h"
#include"Terrain.h"
#include"Camera.h"
#include"EffectManager.h"
#include"DirectGraphics.h"
#include"DirLightSource.h"

MainScene::MainScene()
{
	//ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\fence.fbx");
	EffectManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");

	StageInfo::StageData* pStageData = StageInfo::GetInstance().GetStageData();
	Slime*	pSlime		= new Slime(pStageData->slimeData.pos, D3DXVECTOR3(0.0f, 1.0f, 0.0f), pStageData->slimeData.level);
	m_pCamera			= new Camera(pSlime->GetPos());

	m_PtrObjBases.push_back(pSlime);
}

MainScene::~MainScene()
{
	for (auto ite = m_PtrObjBases.begin(); ite != m_PtrObjBases.end(); ++ite) {
		delete *ite;
	}

	EffectManager::GetpInstance().ReleaseEffect("Shader\\BasicShader.fx");
}

SceneBase::SCENE_ID MainScene::Update()
{
	Lib::GetInstance().UpdateKey();
	Lib::GetInstance().UpdateMouse();
	SceneBase::SCENE_ID retSceneId = SCENE_ID::MAIN;

	DirLightSource::GetpInstance().Update();

	for (auto ite = m_PtrObjBases.begin(); ite != m_PtrObjBases.end(); ++ite) {
		(*ite)->Update();
	}

	m_pCamera->Update();

	return retSceneId;
}

void MainScene::Draw()
{
	Lib::GetInstance().StartRender();

	for (auto ite = m_PtrObjBases.begin(); ite != m_PtrObjBases.end(); ++ite) {
		(*ite)->Draw();
	}

	////Effect‚²‚Æ‚É‚â‚ê‚Î‚¢‚¢
	//D3DXMATRIX ViewMatrix;
	//(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	//D3DXMATRIX ProjMatrix;
	//(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);

	//EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetViewMatrix(&ViewMatrix);
	//EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetProjMatrix(&ProjMatrix);
	//EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetLightVector();

	Lib::GetInstance().EndRender();
}
