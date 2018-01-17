#include "Scaler.h"
#include<Windows.h>

Scaler::Scaler(float maxScale, float initScale, int maxInterval):
	m_Scale(initScale),
	kMaxScale(maxScale),
	kInitScale(initScale),
	kMaxInterval(maxInterval)
{
	if (kMaxInterval == 0) {
		//0Š„‚è‚·‚é‚½‚ß
		MessageBox(0, "•s“–‚È’l‚ª“ü—Í‚³‚ê‚Ü‚µ‚½", 0, MB_OK);
		delete this;
	}
}

Scaler::~Scaler()
{
}

void Scaler::Update() 
{
	if (m_FrCnt <= kMaxInterval) {

		++m_FrCnt;

		m_Scale += (kMaxScale - kInitScale) * (m_FrCnt / kMaxInterval);
	}
}