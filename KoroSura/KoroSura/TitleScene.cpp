#include "TitleScene.h"
#include"Lib.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

SceneBase::SCENE_ID TitleScene::Update()
{
	SCENE_ID retSceneId = TITLE;

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::SPACE) == Utility::BUTTON_STATE::PUSH ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::ENTER) == Utility::BUTTON_STATE::PUSH) {

		m_WasPushedKey = true;
	}

	if (m_WasPushedKey) {
		++m_FrCnt;
	}

	if (m_FrCnt == kNextSceneInterval) {
		retSceneId = STAGESELECT;
		//m_FrCnt = 0;
	}

	return retSceneId;
}

void TitleScene::Draw()
{

}