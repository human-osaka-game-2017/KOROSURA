#include"NowLoadingLogo.h"
#include"Lib.h"
#include"Fonts.h"

NowLoadingLogo::NowLoadingLogo()
{
	Lib::GetInstance().LoadPictureFile("Picture\\UI.png", Fonts::g_PngSize, Fonts::g_PngSize);
	Lib::GetInstance().LoadPictureFile("Picture\\TeamLogo.png", Fonts::g_PngSize, Fonts::g_PngSize);
}

NowLoadingLogo::~NowLoadingLogo()
{
	Lib::GetInstance().CancelTexture("Picture\\TeamLogo.png");
	Lib::GetInstance().CancelTexture("Picture\\UI.png");
}

void NowLoadingLogo::Draw()
{
	m_Deg += kRotasionSpeed;

	Utility::CUSTOMVERTEX drawVertex[] = {
		{ 450 / 2 - 250 / 2,900 / 2 - 250 / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ 450 / 2 + 250 / 2,900 / 2 - 250 / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ 450 / 2 + 250 / 2,900 / 2 + 250 / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ 450 / 2 - 250 / 2,900 / 2 + 250 / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Fonts::GetSlimeUV(drawVertex);
	Lib::GetInstance().Rotation(drawVertex, m_Deg);
	Lib::GetInstance().Draw(drawVertex, "Picture\\TeamLogo.png");
}