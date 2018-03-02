#include"NowLoadingLogo.h"
#include"Lib.h"
#include"Fonts.h"

NowLoadingLogo::NowLoadingLogo()
{
	Lib::GetInstance().LoadPictureFile("Picture\\StageImg.png", kPngWidth, kPngHeight);
}

NowLoadingLogo::~NowLoadingLogo()
{
	Lib::GetInstance().CancelTexture("Picture\\StageImg.png");
}

void NowLoadingLogo::Draw()
{
	m_Deg += kRotasionSpeed;

	//slime‰æ‘œ‚Ì•\Ž¦
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

	Lib::GetInstance().Rotation(SlimeVertex, m_Deg);
	Lib::GetInstance().Draw(SlimeVertex, "Picture\\StageImg.png");
}