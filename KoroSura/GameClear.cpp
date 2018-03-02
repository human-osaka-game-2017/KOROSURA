#include "GameClear.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"SoundBufferManager.h"
#include"Selection.h"
#include"StageInfo.h"


GameClear::GameClear()
{
	m_NextStage = false;
	Lib::GetInstance().LoadPictureFile("Picture\\StageImg.png", kPngWidth, kPngHeight);
	Lib::GetInstance().LoadPictureFile("Picture\\GameClear.png", kBackPngWidth, kBackPngHeight);
	m_pSelecter = new Selecter(2, std::bind(&GameClear::WasSelect, this));
	SoundBufferManager::GetInstance().LoadWaveFile("BGM\\ClearBgm.wav");
}

GameClear::~GameClear()
{
	Lib::GetInstance().CancelTexture("Picture\\StageImg.png");
	Lib::GetInstance().CancelTexture("Picture\\GameClear.png");
	SoundBufferManager::GetInstance().CancelSound("BGM\\ClearBgm.wav");
	delete m_pSelecter;
}

void GameClear::Update()
{
	Lib::GetInstance().UpdateKey();
	m_pSelecter->Update();
	if (m_selectNum == 0) {
		kSlimePos.y = kStageNextPos.y;
	}
	else{
		kSlimePos.y = kStageSelectPos.y;
	}
}

void GameClear::Draw()
{

	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	//clear背景の表示
	Utility::CUSTOMVERTEX BackVertex[] = {
		{ 0,0 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ 1600,0 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ 1600,1000 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ 0,1000 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().Draw(BackVertex, "Picture\\GameClear.png");

	//slime画像の表示
	Utility::CUSTOMVERTEX SlimeVertex[] = {
		{ kSlimePos.x - kSlimeWidth / 2,kSlimePos.y - kSlimeHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kSlimePos.x + kSlimeWidth / 2,kSlimePos.y - kSlimeHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kSlimePos.x + kSlimeWidth / 2,kSlimePos.y + kSlimeHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kSlimePos.x - kSlimeWidth / 2,kSlimePos.y + kSlimeHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		SlimeVertex,
		4300.0f, 700.0f,
		static_cast<float>(kSlimeWidth), static_cast<float>(kSlimeHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));


	Lib::GetInstance().Draw(SlimeVertex, "Picture\\StageImg.png");
	//clear画像の表示
	Utility::CUSTOMVERTEX ClearVertex[] = {
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		ClearVertex,
		0.0, 700.0f,
		static_cast<float>(650.0f), static_cast<float>(kStageClearHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

	Lib::GetInstance().Draw(ClearVertex, "Picture\\StageImg.png");
	if (m_selectNum == 0) {
		//next画像の表示
		Utility::CUSTOMVERTEX NextVertex[] = {
			{ kStageNextPos.x - kStageNextWidth / 2,kStageNextPos.y - kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
			{ kStageNextPos.x + kStageNextWidth / 2,kStageNextPos.y - kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
			{ kStageNextPos.x + kStageNextWidth / 2,kStageNextPos.y + kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
			{ kStageNextPos.x - kStageNextWidth / 2,kStageNextPos.y + kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
		};

		Lib::GetInstance().TrimingVertex(
			NextVertex,
			2800.0f, 700.0f,
			static_cast<float>(kStageNextWidth), static_cast<float>(kStageNextHeight),
			static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));
		Lib::GetInstance().Draw(NextVertex, "Picture\\StageImg.png");
	}
	else {
		//next画像の表示
		Utility::CUSTOMVERTEX NextVertex[] = {
			{ kStageNextPos.x - kStageNextWidth / 2,kStageNextPos.y - kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
			{ kStageNextPos.x + kStageNextWidth / 2,kStageNextPos.y - kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
			{ kStageNextPos.x + kStageNextWidth / 2,kStageNextPos.y + kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
			{ kStageNextPos.x - kStageNextWidth / 2,kStageNextPos.y + kStageNextHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
		};

		Lib::GetInstance().TrimingVertex(
			NextVertex,
			1300.0f, 700.0f,
			static_cast<float>(kStageNextWidth), static_cast<float>(kStageNextHeight),
			static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));
		Lib::GetInstance().Draw(NextVertex, "Picture\\StageImg.png");
	}
	if (m_selectNum != 0) {

		//select画像の表示
		Utility::CUSTOMVERTEX StageSelectVertex[] = {
			{ kStageSelectPos.x - kStageSelectWidth / 2,kStageSelectPos.y - kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
			{ kStageSelectPos.x + kStageSelectWidth / 2,kStageSelectPos.y - kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
			{ kStageSelectPos.x + kStageSelectWidth / 2,kStageSelectPos.y + kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
			{ kStageSelectPos.x - kStageSelectWidth / 2,kStageSelectPos.y + kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
		};

		Lib::GetInstance().TrimingVertex(
			StageSelectVertex,
			3800.0f, 700.0f,
			static_cast<float>(kStageSelectWidth), static_cast<float>(kStageSelectHeight),
			static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

		Lib::GetInstance().Draw(StageSelectVertex, "Picture\\StageImg.png");
	}
	else {
		//select画像の表示
		Utility::CUSTOMVERTEX StageSelectVertex[] = {
			{ kStageSelectPos.x - kStageSelectWidth / 2,kStageSelectPos.y - kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
			{ kStageSelectPos.x + kStageSelectWidth / 2,kStageSelectPos.y - kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
			{ kStageSelectPos.x + kStageSelectWidth / 2,kStageSelectPos.y + kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
			{ kStageSelectPos.x - kStageSelectWidth / 2,kStageSelectPos.y + kStageSelectHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
		};

		Lib::GetInstance().TrimingVertex(
			StageSelectVertex,
			2300.0f, 700.0f,
			static_cast<float>(kStageSelectWidth), static_cast<float>(kStageSelectHeight),
			static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

		Lib::GetInstance().Draw(StageSelectVertex, "Picture\\StageImg.png");
	}
	
}

void GameClear::StartMusic()
{
	SoundBufferManager::GetInstance().PlayBackSound("BGM\\ClearBgm.wav", false);
}
void GameClear::EndMusic()
{
	SoundBufferManager::GetInstance().StopSound("BGM\\ClearBgm.wav");
}

void GameClear::WasSelect()
{
	m_selectNum = m_pSelecter->GetCurrentSelection();
	StageInfo::GetInstance().UnLock();
	if (m_selectNum == 0) {
		StageInfo::GetInstance().SetSelectStage(StageInfo::GetInstance().GetCurrentStage() + 1);
		m_NextStage = true;
	}
	else {
		StageInfo::GetInstance().SetSelectStage(StageInfo::GetInstance().GetCurrentStage() + 1);
	}
}