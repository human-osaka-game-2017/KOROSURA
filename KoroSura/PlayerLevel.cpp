#include"PlayerLevel.h"
#include"Lib.h"
#include"Fonts.h"
#include"DirectGraphics.h"
#include"Renderer.h"

PlayerLevel::PlayerLevel() :
	m_Pos(D3DXVECTOR2(160.0f, 900.0f)),
	m_BackGroundPos(D3DXVECTOR2(210.0f, 900.0f)),
	m_MinslimePos(D3DXVECTOR2(60.0f, 900.0f))
{
}

PlayerLevel::~PlayerLevel()
{
}

void PlayerLevel::Update()
{
}

void PlayerLevel::Draw(int level)
{
	Lib::GetInstance().SetRenderState2D();

	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	//Œã‚ë‚É”Â‚ð•`‰æ
	{
		Utility::CUSTOMVERTEX BackGroundVertex[] = {
			{ m_BackGroundPos.x - BackGround_W / 2,m_BackGroundPos.y - BackGround_H / 2,1.0,1.0,0xffffffff,0.0f,0.0f },
			{ m_BackGroundPos.x + BackGround_W / 2,m_BackGroundPos.y - BackGround_H / 2,1.0,1.0,0xffffffff,1.0f,0.0f },
			{ m_BackGroundPos.x + BackGround_W / 2,m_BackGroundPos.y + BackGround_H / 2,1.0,1.0,0xffffffff,1.0f,1.0f },
			{ m_BackGroundPos.x - BackGround_W / 2,m_BackGroundPos.y + BackGround_H / 2,1.0,1.0,0xffffffff,0.0f,1.0f }
		};

		Lib::GetInstance().TrimingVertex(BackGroundVertex, 0.0f, 490.0f, BackGround_W, BackGround_H, 1024.0f, 1024.0f);
		Lib::GetInstance().Draw(BackGroundVertex, "Picture\\UI.png");
	}

	//ƒXƒ‰ƒCƒ€•`‰æ
	{
		Utility::CUSTOMVERTEX MinSlimeVertex[] = {
			{ m_MinslimePos.x - SLIME_WEIGHT / 2,m_MinslimePos.y - SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,0.0f,0.0f },
			{ m_MinslimePos.x + SLIME_WEIGHT / 2,m_MinslimePos.y - SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,1.0f,0.0f },
			{ m_MinslimePos.x + SLIME_WEIGHT / 2,m_MinslimePos.y + SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,1.0f,1.0f },
			{ m_MinslimePos.x - SLIME_WEIGHT / 2,m_MinslimePos.y + SLIME_HEIGHT / 2,1.0,1.0,0xffffffff,0.0f,1.0f }
		};

		Fonts::GetSlimeUV(MinSlimeVertex);
		Lib::GetInstance().Draw(MinSlimeVertex, "Picture\\UI.png");
	}

	//ƒŒƒxƒ‹•\Ž¦
	{
		Utility::CUSTOMVERTEX vertex[] = {
			{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffffffff,0.0f,0.0f },
			{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffffffff,1.0f,0.0f },
			{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffffffff,1.0f,1.0f },
			{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffffffff,0.0f,1.0f }
		};

		Fonts::GetUV('L', vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
		NextCharPos(vertex);

		Fonts::GetUV('v', vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
		NextCharPos(vertex);

		Fonts::GetUV('/', vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
		NextCharPos(vertex);

		Fonts::GetUV(Utility::TransformChar(level / 10), vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
		NextCharPos(vertex);

		Fonts::GetUV(Utility::TransformChar(level % 10), vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	}
}

void PlayerLevel::NextCharPos(Utility::CUSTOMVERTEX vertex[])
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].x += Fonts::g_Width;
	}
}

