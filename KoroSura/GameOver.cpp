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

}

void GameOver::Draw()
{
	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	//over”wŒi‚Ì•\Ž¦
	Utility::CUSTOMVERTEX BackVertex[] = {
		{ 0,0 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ 1600,0 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ 1600,1000 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ 0,1000 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().Draw(BackVertex, "Picture\\GameOver.png");

	//over‰æ‘œ‚Ì•\Ž¦
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

	//retry‰æ‘œ‚Ì•\Ž¦
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

	//select‰æ‘œ‚Ì•\Ž¦
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
		StageInfo::GetInstance().SetSelectStage(StageInfo::GetInstance().GetCurrentStage());
		m_RetryStage = true;
	}
	else {
		StageInfo::GetInstance().SetSelectStage(StageInfo::GetInstance().GetCurrentStage());
	}
}