#include"TitleScene.h"
#include"Lib.h"
#include"TeamLogo.h"
#include"TitleBackground.h"
#include"PushEnterKeyLogo.h"
#include"Fonts.h"

TitleScene::TitleScene()
{
	Lib::GetInstance().LoadPictureFile("Picture\\UI.png", Fonts::g_PngSize, Fonts::g_PngSize);
	ObjectBase* pTeamLogo = new TeamLogo(std::bind(&TitleScene::CanPushKey, this));

	m_PtrObjects.push_back(pTeamLogo);
}

TitleScene::~TitleScene()
{
	Lib::GetInstance().CancelTexture("Picture\\UI.png");

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		delete *itr;
	}
}

SceneBase::SCENE_ID TitleScene::Update()
{
	SCENE_ID retSceneId = TITLE;

	if (m_WasPushedKey) {
		++m_FrCnt;
	}

	if (m_FrCnt == kNextSceneInterval) {
		retSceneId = STAGESELECT;
	}

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); ++itr){
		(*itr)->Update();
	}

	static bool hasBackground = m_CanPushKey;
	if (hasBackground != m_CanPushKey) {
		m_PtrObjects.push_back(new TitleBackground);
		m_PtrObjects.push_back(new PushEnterKeyLogo(std::bind(&TitleScene::WasPushedKey, this)));
		hasBackground = m_CanPushKey;
	}

	return retSceneId;
}

void TitleScene::Draw()
{

	Lib::GetInstance().SetRenderState2D();

	Lib::GetInstance().StartDraw(0,0,0);

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); ++itr)
	{
		(*itr)->Draw();
	}

	Lib::GetInstance().EndDraw();
}

void TitleScene::CanPushKey() 
{
	m_CanPushKey = true;
}

void TitleScene::WasPushedKey()
{
	m_WasPushedKey = true;
}