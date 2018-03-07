#include "TeamLogo.h"
#include "Lib.h"
#include "Common.h"

TeamLogo::TeamLogo(std::function<void()> function)
	:m_Function(function)
{
	Lib::GetInstance().LoadPictureFile("Picture\\TeamLogo.png", kSize, kSize);
	pFader = new Fader(kInterval, 60);
}

TeamLogo::~TeamLogo()
{
	delete pFader;
}

void TeamLogo::Update() 
{
	pFader->Update();

	++m_FrCnt;

	if (m_FrCnt == kInterval + 60) {
		m_ShouldDraw = false;
		m_Function();
	}
}

void TeamLogo::Draw() 
{
	if (m_ShouldDraw) {

		DWORD color = pFader->GetCurrentColor();

		Utility::CUSTOMVERTEX drawVertex[] ={
			{WINDOW_WIDTH / 2 - kSize / 2,WINDOW_HEIGHT / 2 - kSize / 2 ,1.0f,1.0f,color ,0.0f,0.0f},
			{WINDOW_WIDTH / 2 + kSize / 2,WINDOW_HEIGHT / 2 - kSize / 2 ,1.0f,1.0f,color ,1.0f,0.0f},
			{WINDOW_WIDTH / 2 + kSize / 2,WINDOW_HEIGHT / 2 + kSize / 2 ,1.0f,1.0f,color ,1.0f,1.0f},
			{WINDOW_WIDTH / 2 - kSize / 2,WINDOW_HEIGHT / 2 + kSize / 2 ,1.0f,1.0f,color ,0.0f,1.0f}
		};

		Lib::GetInstance().Draw(drawVertex, "Picture\\TeamLogo.png");
	}
}