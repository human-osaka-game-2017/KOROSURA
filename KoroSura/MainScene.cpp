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
#include"Common.h"
#include"LimitTime.h"
#include"PlayerLevel.h"
#include"SoundBufferManager.h"
#include"GameClear.h"
#include"GameOver.h"
#include"InitProperty.h"
#include"ColliderManager.h"
#include"EnemyManager.h"

void MainScene::Init()
{
}

MainScene::MainScene()
{
	ColliderManager::GetInstance().FormGroup();
	EffectManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx"); 
	SoundBufferManager::GetInstance().LoadWaveFile("BGM\\MainBgm.wav");
	SoundBufferManager::GetInstance().PlayBackSound("BGM\\MainBgm.wav", true);

	StageInfo::StageData* pStageData = StageInfo::GetInstance().GetStageData();

	D3DXVECTOR3 slimePos = pStageData->slimeData.pos;
	slimePos.y += InitProperty::GetInstance().GetInitialData().slimeInitialData.modelOffset;
	Slime*	pSlime		= new Slime(slimePos, D3DXVECTOR3(0.0f, 1.0f, 0.0f), pStageData->slimeData.level, std::bind(&MainScene::SetRetSceneId, this, std::placeholders::_1));
	Sky* pSky			= new Sky();
	Terrain* pTerrain	= new Terrain();

	m_pEnemyManager = new EnemyManager;
	m_pLimitTime = new LimitTime(std::bind(&MainScene::SetRetSceneId, this, std::placeholders::_1));
	m_pCamera	= new Camera(pSlime->GetPos());

	m_PtrMaterials.push_back(pSky);
	m_PtrMaterials.push_back(pTerrain);
	m_PtrMaterials.push_back(pSlime);

	Lib::GetInstance().TransformProjection(45.0f, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0f, 20000.0f);

	D3DXMATRIX ProjMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetProjMatrix(&ProjMatrix);
}

MainScene::~MainScene()
{
	SoundBufferManager::GetInstance().CancelSound("BGM\\MainBgm.wav");
	for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
		delete *ite;
	}
	delete m_pEnemyManager;
	delete m_pLimitTime;
	delete m_pCamera;

	EffectManager::GetpInstance().ReleaseEffect("Shader\\BasicShader.fx");
	PhysicsManager::GetInstance().Initialize();
}

SceneBase::SCENE_ID MainScene::Update()
{
	Lib::GetInstance().UpdateKey();
	Lib::GetInstance().UpdateMouse();

	DirLightSource::GetpInstance().Update();

	for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
		(*ite)->Update();
	}

	m_pEnemyManager->Update();
	m_pLimitTime->Update();

	PhysicsManager::GetInstance().Update();

	ColliderManager::GetInstance().Collide();

	return retId;
}

void MainScene::Draw()
{
	Lib::GetInstance().StartRender();
	DirectGraphics::GetInstance().SetRenderState3D();

	m_pCamera->Update();
	D3DXMATRIX ViewMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetViewMatrix(&ViewMatrix);

	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetLightVector();

	for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
		(*ite)->Draw();
	}
	m_pEnemyManager->Draw();

	Lib::GetInstance().SetRenderState2D();

	m_pLimitTime->Draw();

	Lib::GetInstance().EndRender();
}