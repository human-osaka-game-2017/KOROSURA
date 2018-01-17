#include "SceneManager.h"
#include"SceneFactory.h"

SceneManager::SceneManager()
{
	m_pSceneFactory = new SceneFactory;
	m_pScene = m_pSceneFactory->Create(SceneBase::SCENE_ID::TITLE);
}

SceneManager::~SceneManager()
{
	delete m_pScene;
	delete m_pSceneFactory;
}

void SceneManager::Run()
{
	SceneBase::SCENE_ID nextSceneID = m_pScene->Update();

	m_pScene->Draw();

	if (nextSceneID != m_PreSceneID) {
		delete m_pScene;
		m_pSceneFactory->Create(nextSceneID);
	}
}