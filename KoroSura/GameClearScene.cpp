#include "GameClearScene.h"

GameClearScene::GameClearScene()
{
}

GameClearScene::~GameClearScene()
{
}

SceneBase::SCENE_ID GameClearScene::Update()
{
	SceneBase::SCENE_ID retSceneId = SCENE_ID::GAMECLEAR;

	return retSceneId;
}

void GameClearScene::Draw()
{

}