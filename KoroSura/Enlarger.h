#ifndef SCALER_H
#define SCALER_H

#include <functional>

class Enlarger{
public:
	Enlarger(float maxScale, int maxInterval, float initScale = 0);
	~Enlarger();

	void Update();

	float GetScale() {
		return m_Scale;
	}

	void Reset() {
		m_Scale = kInitScale;
		m_FrCnt = 0;
	}

private:
	float m_Scale = 1.0;
	int m_FrCnt = 0;

	const float kMaxScale;
	const int kMaxInterval;
	const float kInitScale;
};
#endif