#ifndef SCALER_H
#define SCALER_H

#include <functional>
#include "ObjectBase.h"

class Scaler :public ObjectBase{
public:
	Scaler(float maxScale, float initScale, int maxInterval);
	virtual ~Scaler();

	virtual void Update();
	virtual void Draw() {};

	float GetScale() {
		return m_Scale;
	}

private:
	float m_Scale = 1.0;
	int m_FrCnt = 0;

	const float kMaxScale;
	const int kMaxInterval;
	const float kInitScale;
};
#endif