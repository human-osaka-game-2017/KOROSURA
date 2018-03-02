#include "SceneFactory.h"
#include"TitleScene.h"
#include"StageSelectScene.h"
#include"MainScene.h"
#include"GameClearScene.h"
#include"Loading.h"

SceneFactory::SceneFactory()
{
}

SceneFactory::~SceneFactory()
{
}

SceneBase* SceneFactory::Create(SceneBase::SCENE_ID sceneID)
{
	SceneBase* retScene = nullptr;

	switch (sceneID) {
	case SceneBase::SCENE_ID::TITLE:
		retScene = new TitleScene;
		break;

	case SceneBase::SCENE_ID::STAGESELECT:
		retScene = new StageSelectScene;
		break;

	case SceneBase::SCENE_ID::LOAD:
		retScene = new Loading;
		break;

	case SceneBase::SCENE_ID::MAIN:
		retScene = new MainScene;
		break;

	case SceneBase::SCENE_ID::GAMECLEAR:
		retScene = new GameClearScene;
		break;

	case SceneBase::SCENE_ID::GAMEOVER:
		retScene = new GameClearScene;
		break;
	}

	return retScene;
}