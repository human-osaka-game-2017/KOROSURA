#include "SceneFactory.h"
#include"TitleScene.h"
#include"StageSelectScene.h"
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
	}

	return retScene;
}