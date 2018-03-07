#include "Fader.h"

Fader::Fader(int maxInterval, int stoppingInterval):
	m_MaxInterval(maxInterval),
	m_StoppingInterval(stoppingInterval)
{
	if (m_MaxInterval == 0) {
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
	if (m_FrCnt == m_MaxInterval / 2) {
		++m_StoppingFrCnt;
		if (m_StoppingFrCnt >= m_StoppingInterval) {
			++m_FrCnt;
			m_StoppingFrCnt = 0;
		}
	}
	else {
		++m_FrCnt;
	}

	if (m_FrCnt >= m_MaxInterval) {
		m_FrCnt = 0;
	}
	
	DWORD alpha = 0x00;

	if(m_FrCnt <= m_MaxInterval / 2) {
		alpha = (static_cast<float>(m_FrCnt) / static_cast<float>(m_MaxInterval / 2)) * 0xff;
	}
	else {
		alpha = (static_cast<float>((m_MaxInterval) - m_FrCnt) / static_cast<float>(m_FrCnt)) * 0xff;
	}

	m_Color = ((((alpha) & 0xff) << 24) | (((0xff) & 0xff) << 16) | (((0xff) & 0xff) << 8) | ((0xff) & 0xff));
}