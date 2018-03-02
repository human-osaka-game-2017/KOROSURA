#include"StageLogo.h"
#include"StageInfo.h"
#include"Fonts.h"
#include"Lib.h"

StageLogo::StageLogo():
	m_Pos(D3DXVECTOR2(217.5f,100.0f))
{
	Lib::GetInstance().LoadPictureFile("Picture\\Frame.png", kFrameWidth, kFrameHeight);
}

StageLogo::~StageLogo()
{
	Lib::GetInstance().CancelTexture("Picture\\Frame.png");
}

void StageLogo::Update()
{
}

void StageLogo::Draw()
{
	//選ばれているステージ番号に枠を表示する
	//枠の座標
	D3DXVECTOR2 FramePos = D3DXVECTOR2(240.0f, m_Pos.y + (m_SelectPoint*kFontHeight));
	Lib::GetInstance().Draw(FramePos, "Picture\\Frame.png", static_cast<float>(kFrameWidth), static_cast<float>(kFrameHeight));
	for (int i = 0; i < StageInfo::kStageMax; ++i) {
		DrawStageFonts(i);
	}
}

void StageLogo::DrawStageFonts(int num)
{
	Utility::CUSTOMVERTEX vertex[] = {
		{ m_Pos.x - kFontWidth / 2,m_Pos.y + (num * kFontHeight) - kFontHeight / 2,1.0,1.0,0xffffffff,0.0f,0.0f },
		{ m_Pos.x + kFontWidth / 2,m_Pos.y + (num * kFontHeight) - kFontHeight / 2,1.0,1.0,0xffffffff,1.0f,0.0f },
		{ m_Pos.x + kFontWidth / 2,m_Pos.y + (num * kFontHeight) + kFontHeight / 2,1.0,1.0,0xffffffff,1.0f,1.0f },
		{ m_Pos.x - kFontWidth / 2,m_Pos.y + (num * kFontHeight) + kFontHeight / 2,1.0,1.0,0xffffffff,0.0f,1.0f }
	};

	Fonts::GetUV('S', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('t', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('a', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('g', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('e', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV(TransformChar(num + 1), vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
}

void StageLogo::NextCharPos(Utility::CUSTOMVERTEX vertex[])
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].x += kFontWidth;
	}
}

char StageLogo::TransformChar(int val)
{
	char ret;

	switch (val) {
	case 0:
		ret = '0';
		break;

	case 1:
		ret = '1';
		break;

	case 2:
		ret = '2';
		break;

	case 3:
		ret = '3';
		break;

	case 4:
		ret = '4';
		break;

	case 5:
		ret = '5';
		break;

	case 6:
		ret = '6';
		break;

	case 7:
		ret = '7';
		break;

	case 8:
		ret = '8';
		break;

	case 9:
		ret = '9';
		break;
	}

	return ret;
}