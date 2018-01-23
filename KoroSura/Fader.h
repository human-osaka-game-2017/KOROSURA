#ifndef FADER_H
#define FADER_H

#include "ObjectBase.h"
#include<Windows.h>

class Fader :public ObjectBase{
public:
	//フェードインとアウトの総フレーム数
	Fader(int maxInterval, int stoppingInterval = 0);
	virtual ~Fader();

	virtual void Update();
	virtual void Draw() {};

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