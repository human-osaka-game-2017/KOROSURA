#include"GameClearScene.h"
#include"Lib.h"

GameClearScene::GameClearScene()
{
	m_pGameClear = new GameClear();
	m_pGameClear->StartMusic();
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