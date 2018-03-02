#include"GameOverScene.h"
#include"Lib.h"

GameOverScene::GameOverScene()
{
	m_pGameOver = new GameOver();
	m_pGameOver->StartMusic();
}

GameOverScene::~GameOverScene()
{
	m_pGameOver->EndMusic();
	delete m_pGameOver;
}

SceneBase::SCENE_ID GameOverScene::Update()
{
	SceneBase::SCENE_ID retSceneId = SCENE_ID::GAMECLEAR;
	Lib::GetInstance().UpdateKey();
	m_pGameOver->Update();
	if (m_pGameOver->GetRetryStage() == true) {
		retSceneId = SCENE_ID::MAIN;
	}

	return retSceneId;
}

void GameOverScene::Draw()
{
	Lib::GetInstance().StartRender();
	Lib::GetInstance().SetRenderState2D();
	m_pGameOver->Draw();
	Lib::GetInstance().EndRender();
}