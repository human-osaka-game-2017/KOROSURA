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

MainScene::MainScene()
{
	ColliderManager::GetInstance().FormGroup();
	EffectManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx"); 
	SoundBufferManager::GetInstance().LoadWaveFile("BGM\\MainBgm.wav");
	SoundBufferManager::GetInstance().PlayBackSound("BGM\\MainBgm.wav", true);

	StageInfo::StageData* pStageData = StageInfo::GetInstance().GetStageData();

	D3DXVECTOR3 slimePos = pStageData->slimeData.pos;
	slimePos.y += InitProperty::GetInstance().GetInitialData().slimeInitialData.modelOffset;
	Slime*	pSlime		= new Slime(slimePos, D3DXVECTOR3(0.0f, 1.0f, 0.0f), pStageData->slimeData.level);
	Sky* pSky			= new Sky();
	Terrain* pTerrain	= new Terrain();

	m_pLimitTime = new LimitTime();
	m_pCamera	= new Camera(pSlime->GetPos());

	m_ClearFlg = true;
	int enemyNum = pStageData->enemyNum;
	for (int i = 0; i < enemyNum; ++i) {
		EnemyBase* pEnemy = new EnemyBase(pStageData->enemyData[i].pos, D3DXVECTOR3(0.0f, 1.0f, 0.0f), pStageData->enemyData[i].level,
			static_cast<EnemyBase::ENEMY_KIND>(pStageData->enemyData[i].kind), pStageData->enemyData[i].angle, pStageData->enemyData[i].isBoss);
		m_PtrMaterials.push_back(pEnemy);
	}

	m_PtrMaterials.push_back(pSky);
	m_PtrMaterials.push_back(pSlime);
	m_PtrMaterials.push_back(pTerrain);

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

	EffectManager::GetpInstance().ReleaseEffect("Shader\\BasicShader.fx");
}

SceneBase::SCENE_ID MainScene::Update()
{
	SceneBase::SCENE_ID retSceneId = SCENE_ID::MAIN;

	Lib::GetInstance().UpdateKey();
	if (m_ClearFlg != false) {
		m_PtrObject.push_back(m_pGameClear);
	}
	else {

		Lib::GetInstance().UpdateMouse();

		DirLightSource::GetpInstance().Update();

		for (auto ite = m_PtrMaterials.begin(); ite != m_PtrMaterials.end(); ++ite) {
			(*ite)->Update();
		}

		PhysicsManager::GetInstance().Update();
	}

	return retSceneId;
}

void MainScene::Draw()
{
	if (m_ClearFlg != false) {
		Lib::GetInstance().StartRender();
		Lib::GetInstance().SetRenderState2D();
		for (auto ite = m_PtrObject.begin(); ite != m_PtrObject.end(); ++ite) {
			(*ite)->Draw();
		}
		Lib::GetInstance().EndRender();
	}
	else {
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

		Lib::GetInstance().SetRenderState2D();

		m_pLimitTime->Draw();

		Lib::GetInstance().EndRender();
	}
}