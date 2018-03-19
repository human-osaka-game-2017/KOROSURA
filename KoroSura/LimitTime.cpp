#include"LimitTime.h"
#include"Lib.h"
#include"Fonts.h"
#include"DirectGraphics.h"


LimitTime::LimitTime(std::function<void(SceneBase::SCENE_ID)> function, int limit_s):
	m_Pos(D3DXVECTOR2(600.0f, 50.0f)),
	m_Function(function),
	m_Limit_s(limit_s)
{
}


LimitTime::~LimitTime()
{
}

void LimitTime::Update()
{
	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::T) == Utility::BUTTON_STATE::PUSH) {
		m_CanWatched = !m_CanWatched;
	}

	if (m_CanWatched) {
		++m_FrCnt;
		if (m_FrCnt == 60) {
			m_FrCnt = 0;
			--m_Limit_s;
		}

		if (m_Limit_s == 0) {
			m_Function(SceneBase::SCENE_ID::GAMEOVER);
		}
	}
}


void LimitTime::Draw()
{

	Utility::CUSTOMVERTEX vertex[] = {
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffffffff,0.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,0xffffffff,1.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffffffff,1.0f,1.0f },
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,0xffffffff,0.0f,1.0f }
	};

	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	Fonts::GetUV('T', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('i', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('m', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('e', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	//百の位表示
	{
		int hundredsPlace = m_Limit_s / 100;
		Fonts::GetUV(Utility::TransformChar(hundredsPlace), vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
		NextCharPos(vertex);
	}

	//十の位表示
	{
		int tenPlace = (m_Limit_s / 10) % 10;
		Fonts::GetUV(Utility::TransformChar(tenPlace), vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
		NextCharPos(vertex);
	}

	//一の位表示
	{
		int onesPlace = m_Limit_s % 10;
		Fonts::GetUV(Utility::TransformChar(onesPlace), vertex);
		Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	}
}

void LimitTime::NextCharPos(Utility::CUSTOMVERTEX vertex[])
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].x += Fonts::g_Width;
	}
}
