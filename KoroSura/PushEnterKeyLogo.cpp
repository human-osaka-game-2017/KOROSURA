#include"PushEnterKeyLogo.h"
#include"Fader.h"
#include"Lib.h"
#include"Fonts.h"

PushEnterKeyLogo::PushEnterKeyLogo(std::function<void()> function):
	m_Pos(D3DXVECTOR2(436.0f,800.0f)),
	m_Function(function)
{
	m_pFader = new Fader(120, 30);
}

PushEnterKeyLogo::~PushEnterKeyLogo()
{
	delete m_pFader;
}

void PushEnterKeyLogo::Update()
{
	m_pFader->Update();

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::ENTER) == Utility::BUTTON_STATE::PUSH ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::SPACE) == Utility::BUTTON_STATE::PUSH) {

		m_Function();
		m_pFader->SetMaxInterval(5);
		m_pFader->SetStoppingInterval(0);
	}
}

void PushEnterKeyLogo::Draw()
{
	DWORD color = m_pFader->GetCurrentColor();

	Utility::CUSTOMVERTEX vertex[] = {
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,color,0.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y - Fonts::g_Height / 2,1.0,1.0,color,1.0f,0.0f },
		{ m_Pos.x + Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,color,1.0f,1.0f },
		{ m_Pos.x - Fonts::g_Width / 2,m_Pos.y + Fonts::g_Height / 2,1.0,1.0,color,0.0f,1.0f }
	};

	Fonts::GetUV('P', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('u', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('s', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('h', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	NextCharPos(vertex);

	Fonts::GetUV('E', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('n', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('t', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('e', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('r', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	NextCharPos(vertex);

	Fonts::GetUV('K', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('e', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);

	Fonts::GetUV('y', vertex);
	Lib::GetInstance().Draw(vertex, "Picture\\UI.png");
	NextCharPos(vertex);
}

void PushEnterKeyLogo::NextCharPos(Utility::CUSTOMVERTEX vertex[])
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].x += Fonts::g_Width;
	}
}
