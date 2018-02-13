#include"Loading.h"
#include"Loader.h"
#include"NowLoadingLogo.h"
#include"Lib.h"

Loading::Loading()
{
	m_pLoader = new Loader;
	m_pNowLoadingLogo = new NowLoadingLogo;

	DWORD threadId;

	// スレッドの作成 
	HANDLE m_hThread = CreateThread(NULL, 0,
		Loader::Load, static_cast<LPVOID>(m_pLoader),
		CREATE_SUSPENDED, &threadId);

	// スレッドの起動 
	ResumeThread(m_hThread);
}

Loading::~Loading()
{
	CloseHandle(m_hThread);

	delete m_pLoader;
}

SceneBase::SCENE_ID Loading::Update()
{
	SceneBase::SCENE_ID retSceneId = SCENE_ID::LOAD;

	DWORD loadResult;

	//スレッドが終了しているかチェック
	GetExitCodeThread(m_hThread, &loadResult);
	if (loadResult != STILL_ACTIVE) {
		retSceneId = SCENE_ID::MAIN;
	}

	return retSceneId;
}

void Loading::Draw()
{
	Lib::GetInstance().SetRenderState2D();

	Lib::GetInstance().StartDraw(0, 0, 0);

	m_pNowLoadingLogo->Draw();

	Lib::GetInstance().EndDraw();
}