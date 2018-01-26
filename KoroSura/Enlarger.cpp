#include "Enlarger.h"
#include<Windows.h>

Enlarger::Enlarger(float maxScale, int maxInterval, float initScale):
	m_Scale(initScale),
	kMaxScale(maxScale),
	kInitScale(initScale),
	kMaxInterval(maxInterval)
{
	if (kMaxInterval == 0) {
		//0���肷�邽��
		MessageBox(0, "�s���Ȓl�����͂���܂���", 0, MB_OK);
		delete this;
	}
}

Enlarger::~Enlarger()
{
}

void Enlarger::Update() 
{
	if (m_FrCnt <= kMaxInterval) {

		++m_FrCnt;

		m_Scale += (kMaxScale - kInitScale) * (m_FrCnt / kMaxInterval);
	}
}