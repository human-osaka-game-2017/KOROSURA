#include"PlayerLevel.h"
#include"Lib.h"
#include"Fonts.h"
#include"DirectGraphics.h"
#include"Renderer.h"

PlayerLevel::PlayerLevel() :
	m_Pos(D3DXVECTOR2(100.0f, 900.0f)),
	m_BackGroundPos(D3DXVECTOR2(70.0f, 900.0f)),
	m_MinslimePos(D3DXVECTOR2(60.0f, 900.0f))
{
	Lib::GetInstance().LoadPictureFile("Picture\\TimeLimitBack.jpg", Fonts::g_PngSize, Fonts::g_PngSize);
}


PlayerLevel::~PlayerLevel()
{
}
void PlayerLevel::Update()
{
}


void PlayerLevel::Draw(int level)
{

	Utility::CUSTOMVERTEX vertex[] = {
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffffffff,0.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffffffff,1.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffffffff,1.0f,1.0f },
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffffffff,0.0f,1.0f }
	};
	Utility::CUSTOMVERTEX BackGroundVertex[] = {
		{ m_BackGroundPos.x - BackGround_W / 2,m_BackGroundPos.y - BackGround_H  / 2,1.0,1.0,0xffffffff,0.0f,0.478f },
		{ m_BackGroundPos.x + BackGround_W / 2,m_BackGroundPos.y - BackGround_H  / 2,1.0,1.0,0xffffffff,0.449f,0.478f },
		{ m_BackGroundPos.x + BackGround_W / 2,m_BackGroundPos.y + BackGround_H  / 2,1.0,1.0,0xffffffff,0.449f,0.634f },
		{ m_BackGroundPos.x - BackGround_W / 2,m_BackGroundPos.y + BackGround_H  / 2,1.0,1.0,0xffffffff,0.0f,0.634f }
	};
	Utility::CUSTOMVERTEX MinSlimeVertex[] = {
		{ m_MinslimePos.x - SLIME_W / 2,m_MinslimePos.y - SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,0.524f,0.683f },
		{ m_MinslimePos.x + SLIME_W / 2,m_MinslimePos.y - SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,0.543f,0.683f },
		{ m_MinslimePos.x + SLIME_W / 2,m_MinslimePos.y + SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,0.543f,0.830f },
		{ m_MinslimePos.x - SLIME_W / 2,m_MinslimePos.y + SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,0.524f,0.830f }
	};
	Lib::GetInstance().SetRenderState2D();

	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Lib::GetInstance().Draw(BackGroundVertex, "Picture\\TimeLimitBack.jpg");
	Lib::GetInstance().Draw(MinSlimeVertex, "Picture\\UI.png");

	Fonts::GetUV('L', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('v', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('/', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV(Utility::TransformChar(level), vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
}
void PlayerLevel::NextCharPos(Utility::CUSTOMVERTEX vertex[])
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].x += Fonts::g_Width;
	}
}

