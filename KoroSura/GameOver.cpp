#include "GameOver.h"
#include"Lib.h"


GameOver::GameOver()
{
	Lib::GetInstance().LoadPictureFile("Picture\\Select.png", kPngWidth, kPngHeight);
}


GameOver::~GameOver()
{
	Lib::GetInstance().CancelTexture("Picture\\Select.png");
}

void GameOver::Update()
{

}

void GameOver::Draw()
{
	//select‰æ‘œ‚Ì•\Ž¦
	Utility::CUSTOMVERTEX OverVertex[] = {
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y - kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kStageClearPos.x + kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kStageClearPos.x - kStageClearWidth / 2,kStageClearPos.y + kStageClearHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		OverVertex,
		700.0f, 875.0f,
		static_cast<float>(kStageClearWidth), static_cast<float>(kStageClearHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

	Lib::GetInstance().Draw(OverVertex, "Picture\\Select.png.png");
}


