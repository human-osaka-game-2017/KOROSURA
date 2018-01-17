#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include"SceneBase.h"

class SceneFactory;

class SceneManager{
public:
	SceneManager();
	~SceneManager();

	void Run();

private:
	SceneBase::SCENE_ID m_PreSceneID;
	SceneBase* m_pScene;
	SceneFactory* m_pSceneFactory;
};
#endif