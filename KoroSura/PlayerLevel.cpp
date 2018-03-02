#include"PlayerLevel.h"
#include"Lib.h"
#include"Fonts.h"
#include"DirectGraphics.h"


PlayerLevel::PlayerLevel() :
	m_Pos(D3DXVECTOR2(50.0f, 900.0f))
{
}


PlayerLevel::~PlayerLevel()
{
}
void PlayerLevel::Update()
{
}


void PlayerLevel::Draw()
{

	Utility::CUSTOMVERTEX vertex[] = {
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffff0000,0.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffff0000,1.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffff0000,1.0f,1.0f },
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffff0000,0.0f,1.0f }
	};
	Lib::GetInstance().SetRenderState2D();
	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Fonts::GetUV('L', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('e', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('v', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('e', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('l', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('1', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);
}
void PlayerLevel::NextCharPos(Utility::CUSTOMVERTEX vertex[])
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].x += Fonts::g_Width;
	}
}
