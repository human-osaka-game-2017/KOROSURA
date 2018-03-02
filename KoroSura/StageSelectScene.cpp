#include"StageSelectScene.h"
#include"Selection.h"
#include"StageInfo.h"
#include"StageSelectBase.h"
#include"StageLogo.h"
#include"Description.h"
#include"StageSelectBackground.h"
#include"Fonts.h"
#include"Lib.h"
#include"SoundBufferManager.h"

StageSelectScene::StageSelectScene()
{
	Lib::GetInstance().LoadPictureFile("Picture\\UI.png", Fonts::g_PngSize, Fonts::g_PngSize);

	SoundBufferManager::GetInstance().LoadWaveFile("BGM\\StageSelectBgm.wav");

	m_pSelecter = new Selecter(StageInfo::kStageMax, std::bind(&StageSelectScene::WasSelected, this));

	StageSelectBackground* pStageSelectBackground	= new StageSelectBackground();
	StageLogo* pStageLogo							= new StageLogo();
	Description* pDescription						= new Description();

	m_PtrObjects.push_back(pStageSelectBackground);
	m_PtrObjects.push_back(pStageLogo);
	m_PtrObjects.push_back(pDescription);
}

StageSelectScene::~StageSelectScene()
{
	Lib::GetInstance().CancelTexture("Picture\\UI.png");

	SoundBufferManager::GetInstance().CancelSound("BGM\\StageSelectBgm.wav");

	delete m_pSelecter;
	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); ++itr) {
		delete *itr;
	}
}

SceneBase::SCENE_ID StageSelectScene::Update()
{
	SCENE_ID retSceneId = SCENE_ID::STAGESELECT;

	Lib::GetInstance().UpdateKey();

	SoundBufferManager::GetInstance().PlayBackSound("BGM\\StageSelectBgm.wav",true);

	m_pSelecter->Update();
	int selectPoint = m_pSelecter->GetCurrentSelection();
	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); ++itr) {
		(*itr)->SetSelectPoint(selectPoint);
		(*itr)->Update();
	}

	if (m_WasSelected) {
		++m_FrCnt;
	}

	if (m_FrCnt >= kNextSceneInterval) {
		retSceneId = SCENE_ID::LOAD;
	}


	return retSceneId;
}

void StageSelectScene::Draw()
{
	Lib::GetInstance().SetRenderState2D();

	Lib::GetInstance().StartDraw(0, 0, 0);

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); ++itr) {
		(*itr)->Draw();
	}

	Lib::GetInstance().EndDraw();
}

void StageSelectScene::WasSelected()
{
	int selectNum = m_pSelecter->GetCurrentSelection();
	if (selectNum <= StageInfo::GetInstance().GetUnLockingStage()) {
		m_WasSelected = true;
		StageInfo::GetInstance().SetSelectStage(selectNum);
	}
}