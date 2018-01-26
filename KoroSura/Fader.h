#ifndef FADER_H
#define FADER_H

#include<Windows.h>

class Fader{
public:
	//フェードインとアウトの総フレーム数
	Fader(int maxInterval, int stoppingInterval = 0);
	~Fader();

	void Update();

	DWORD GetCurrentColor() {
		return m_Color;
	}

	void SetMaxInterval(int interval) {
		m_MaxInterval = interval;
	}

	void SetStoppingInterval(int interval) {
		m_StoppingInterval = interval;
	}

private:
	DWORD m_Color = 0x00000000;
	int m_FrCnt = 0;
	int m_StoppingFrCnt = 0;
	int m_MaxInterval;
	int m_StoppingInterval;
};
#endif