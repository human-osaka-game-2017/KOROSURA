#include "GameClear.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"SoundBufferManager.h"


GameClear::GameClear()
{
	Lib::GetInstance().LoadPictureFile("Picture\\Select.png", kPngWidth, kPngHeight);
	SoundBufferManager::GetInstance().LoadWaveFile("BGM\\ClearBgm.wav");
	SoundBufferManager::GetInstance().PlayBackSound("BGM\\ClearBgm.wav", false);
}

GameClear::~GameClear()
{
	Lib::GetInstance().CancelTexture("Picture\\Select.png");
	SoundBufferManager::GetInstance().StopSound("BGM\\ClearBgm.wav");
	SoundBufferManager::GetInstance().CancelSound("BGM\\ClearBgm.wav");
}

void GameClear::Update()
{

}

void GameClear::Draw()
{
	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	//clear‰æ‘œ‚Ì•\Ž¦
	Utility::CUSTOMVERTEX ClearVertex[] = {
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		ClearVertex,
		0.0, 700.0f,
		static_cast<float>(kStageClearWidth), static_cast<float>(kStageClearHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

	Lib::GetInstance().Draw(ClearVertex, "Picture\\Select.png");

	//next‰æ‘œ‚Ì•\Ž¦
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

	Lib::GetInstance().Draw(NextVertex, "Picture\\Select.png");
}