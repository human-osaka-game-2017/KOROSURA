#include"GameClearScene.h"
#include"Lib.h"
#include"StageInfo.h"

GameClearScene::GameClearScene()
{
	m_pGameClear = new GameClear();
	m_pGameClear->StartMusic();

	//ƒAƒ“ƒƒbƒN
	if (StageInfo::GetInstance().GetCurrentStage() == StageInfo::GetInstance().GetUnLockingStage()) {
		StageInfo::GetInstance().UnLock();
	}
}

GameClearScene::~GameClearScene()
{
	m_pGameClear->EndMusic();
	delete m_pGameClear;
}

SceneBase::SCENE_ID GameClearScene::Update()
{
	SceneBase::SCENE_ID retSceneId = SCENE_ID::GAMECLEAR;
	Lib::GetInstance().UpdateKey();
	m_pGameClear->Update();
	if (m_pGameClear->GetNextStage() == true) {
		retSceneId = SCENE_ID::LOAD;
	}
	else if (m_pGameClear->GetSelectStage() == true) {
		retSceneId = SCENE_ID::STAGESELECT;
		StageInfo::GetInstance().DeleteStageData();
	}
	
	return retSceneId;
}

void GameClearScene::Draw()
{
	Lib::GetInstance().StartRender();
	Lib::GetInstance().SetRenderState2D();
	m_pGameClear->Draw();
	Lib::GetInstance().EndRender();
}