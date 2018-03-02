#include"GameOver.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"SoundBufferManager.h"


GameOver::GameOver()
{
	Lib::GetInstance().LoadPictureFile("Picture\\Select.png", kPngWidth, kPngHeight);
	SoundBufferManager::GetInstance().LoadWaveFile("BGM\\EndingBgm.wav");
}


GameOver::~GameOver()
{
	Lib::GetInstance().CancelTexture("Picture\\Select.png");
	SoundBufferManager::GetInstance().StopSound("BGM\\EndingBgm.wav");
	SoundBufferManager::GetInstance().CancelSound("BGM\\EndingBgm.wav");
}

void GameOver::Update()
{

}

void GameOver::Draw()
{

	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
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
		static_cast<float>(kStageOverWidth), static_cast<float>(kStageOverHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));


	Lib::GetInstance().Draw(OverVertex, "Picture\\Select.png");

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

	Lib::GetInstance().Draw(RetryVertex, "Picture\\Select.png");

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

	Lib::GetInstance().Draw(StageSelectVertex, "Picture\\Select.png");
}

void GameOver::StartMusic()
{
	SoundBufferManager::GetInstance().PlayBackSound("BGM\\EndingBgm.wav", false);
}

void GameOver::EndMusic()
{
	SoundBufferManager::GetInstance().StopSound("BGM\\EndingBgm.wav");
}