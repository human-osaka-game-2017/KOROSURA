#include"GameOver.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"SoundBufferManager.h"
#include"Selection.h"
#include"StageInfo.h"


GameOver::GameOver()
{
	m_RetryStage = false;
	Lib::GetInstance().LoadPictureFile("Picture\\StageImg.png", kPngWidth, kPngHeight);
	Lib::GetInstance().LoadPictureFile("Picture\\GameOver.png", kBackPngWidth, kBackPngHeight);
	m_pSelecter = new Selecter(2, std::bind(&GameOver::WasSelect, this));
	SoundBufferManager::GetInstance().LoadWaveFile("BGM\\EndingBgm.wav");
}


GameOver::~GameOver()
{
	Lib::GetInstance().CancelTexture("Picture\\StageImg.png");
	Lib::GetInstance().CancelTexture("Picture\\GameOver.png");
	SoundBufferManager::GetInstance().CancelSound("BGM\\EndingBgm.wav");
	delete m_pSelecter;
}

void GameOver::Update()
{
	m_pSelecter->Update();
	m_selectNum = m_pSelecter->GetCurrentSelection();
	if (m_selectNum == 0) {
		kSlimePos.y = kStageRetryPos.y;
	}
	else {
		kSlimePos.y = kStageSelectPos.y;
	}

}

void GameOver::Draw()
{
	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	//over背景の表示
	Utility::CUSTOMVERTEX BackVertex[] = {
		{ 0,0 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ 1600,0 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ 1600,1000 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ 0,1000 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().Draw(BackVertex, "Picture\\GameOver.png");

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

	//over画像の表示
	Utility::CUSTOMVERTEX OverVertex[] = {
		{ kStageOverPos.x - kStageOverWidth / 2,kStageOverPos.y - kStageOverHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kStageOverPos.x + kStageOverWidth / 2,kStageOverPos.y - kStageOverHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kStageOverPos.x + kStageOverWidth / 2,kStageOverPos.y + kStageOverHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kStageOverPos.x - kStageOverWidth / 2,kStageOverPos.y + kStageOverHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		OverVertex,
		650.0f, 700.0f,
		static_cast<float>(650.0f), static_cast<float>(kStageOverHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));



	Lib::GetInstance().Draw(OverVertex, "Picture\\StageImg.png");
	if (m_selectNum == 0) {
		//retry画像の表示
		Utility::CUSTOMVERTEX RetryVertex[] = {
			{ kStageRetryPos.x - kStageRetryWidth / 2,kStageRetryPos.y - kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
			{ kStageRetryPos.x + kStageRetryWidth / 2,kStageRetryPos.y - kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
			{ kStageRetryPos.x + kStageRetryWidth / 2,kStageRetryPos.y + kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
			{ kStageRetryPos.x - kStageRetryWidth / 2,kStageRetryPos.y + kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
		};

		Lib::GetInstance().TrimingVertex(
			RetryVertex,
			3300.0f, 700.0f,
			static_cast<float>(kStageRetryWidth), static_cast<float>(kStageRetryHeight),
			static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

		Lib::GetInstance().Draw(RetryVertex, "Picture\\StageImg.png");
	}
	else {
		//retry画像の表示
		Utility::CUSTOMVERTEX RetryVertex[] = {
			{ kStageRetryPos.x - kStageRetryWidth / 2,kStageRetryPos.y - kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
			{ kStageRetryPos.x + kStageRetryWidth / 2,kStageRetryPos.y - kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
			{ kStageRetryPos.x + kStageRetryWidth / 2,kStageRetryPos.y + kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
			{ kStageRetryPos.x - kStageRetryWidth / 2,kStageRetryPos.y + kStageRetryHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
		};

		Lib::GetInstance().TrimingVertex(
			RetryVertex,
			1800.0f, 700.0f,
			static_cast<float>(kStageRetryWidth), static_cast<float>(kStageRetryHeight),
			static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

		Lib::GetInstance().Draw(RetryVertex, "Picture\\StageImg.png");
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

void GameOver::StartMusic()
{
	SoundBufferManager::GetInstance().PlayBackSound("BGM\\EndingBgm.wav", false);
}

void GameOver::EndMusic()
{
	SoundBufferManager::GetInstance().StopSound("BGM\\EndingBgm.wav");
}

void GameOver::WasSelect()
{
	m_selectNum = m_pSelecter->GetCurrentSelection();
	if (m_selectNum == 0) {
		m_RetryStage = true;
	}
	else {
		m_Select = true;
	}
}