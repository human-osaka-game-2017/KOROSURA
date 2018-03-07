#include "TitleBackground.h"
#include "Lib.h"
#include "Common.h"

TitleBackground::TitleBackground()
{
	Lib::GetInstance().LoadPictureFile("Picture\\Title.png", WINDOW_WIDTH, WINDOW_HEIGHT);
}

TitleBackground::~TitleBackground()
{
}

void TitleBackground::Draw()
{
	D3DXVECTOR2 pos = { WINDOW_WIDTH / 2.0f,WINDOW_HEIGHT / 2.0f };
	Lib::GetInstance().Draw(pos, "Picture\\Title.png", WINDOW_WIDTH, WINDOW_HEIGHT);
}