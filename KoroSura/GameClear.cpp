#include "GameClear.h"
#include"Lib.h"


GameClear::GameClear()
{
	Lib::GetInstance().LoadPictureFile("Picture\\Select.png", kPngWidth, kPngHeight);
}

GameClear::~GameClear()
{
	Lib::GetInstance().CancelTexture("Picture\\Select.png");
}

void GameClear::Update()
{

}

void GameClear::Draw()
{
	//select‰æ‘œ‚Ì•\Ž¦
	Utility::CUSTOMVERTEX ClearVertex[] = {
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		ClearVertex,
		700.0f, 650.0f,
		static_cast<float>(kStageClearWidth), static_cast<float>(kStageClearHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

	Lib::GetInstance().Draw(ClearVertex, "Picture\\Select.png");
}