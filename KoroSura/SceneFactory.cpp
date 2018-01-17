#include "SceneFactory.h"
#include"TitleScene.h"
#include"StageSelectScene.h"
#include"MainScene.h"
#include"ResultScene.h"

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

	case SceneBase::SCENE_ID::MAIN:
		retScene = new MainScene;
		break;

	case SceneBase::SCENE_ID::RESULT:
		retScene = new ResultScene;
		break;
	}

	return retScene;
}