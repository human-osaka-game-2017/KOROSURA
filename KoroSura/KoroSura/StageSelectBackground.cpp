#include"StageSelectBackground.h"
#include"Lib.h"
#include"Common.h"

StageSelectBackground::StageSelectBackground()
{
	Lib::GetInstance().LoadPictureFile("Picture\\StageSelect.png", WINDOW_WIDTH, WINDOW_HEIGHT);
}


StageSelectBackground::~StageSelectBackground()
{
	Lib::GetInstance().CancelTexture("Picture\\StageSelect.png");
}

void StageSelectBackground::Update()
{
}

void StageSelectBackground::Draw()
{
	D3DXVECTOR2 pos = { WINDOW_WIDTH / 2.0f,WINDOW_HEIGHT / 2.0f };
	Lib::GetInstance().Draw(pos, "Picture\\StageSelect.png", WINDOW_WIDTH, WINDOW_HEIGHT);
}
