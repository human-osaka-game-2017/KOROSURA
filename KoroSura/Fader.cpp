#include "Fader.h"

Fader::Fader(int maxInterval, int stoppingInterval):
	kMaxInterval(maxInterval),
	kStoppingInterval(stoppingInterval)
{
	if (kMaxInterval == 0) {
		//0Š„‚è‚·‚é‚½‚ß
		MessageBox(0, "•s“–‚È’l‚ª“ü—Í‚³‚ê‚Ü‚µ‚½", 0, MB_OK);
		delete this;
	}
}

Fader::~Fader()
{
}

void Fader::Update()
{
	if (m_FrCnt == kMaxInterval / 2) {
		++m_StoppingFrCnt;
		if (m_StoppingFrCnt == kStoppingInterval) {
			++m_FrCnt;
		}
	}
	else {
		++m_FrCnt;
	}

	if (m_FrCnt == kMaxInterval) {
		m_FrCnt = 0;
	}
	
	DWORD alpha = 0x00;

	if(m_FrCnt <= kMaxInterval / 2) {
		alpha = (static_cast<float>(m_FrCnt) / static_cast<float>(kMaxInterval / 2)) * 0xff;
	}
	else {
		alpha = (static_cast<float>((kMaxInterval) - m_FrCnt) / static_cast<float>(m_FrCnt)) * 0xff;
	}

	m_Color = ((((alpha) & 0xff) << 24) | (((0xff) & 0xff) << 16) | (((0xff) & 0xff) << 8) | ((0xff) & 0xff));
}