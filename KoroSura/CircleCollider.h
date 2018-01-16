#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include"ColliderBase.h"

class CircleCollider :public ColliderBase {
public:
	CircleCollider(const std::string className, const D3DXVECTOR3& pos, std::function<void()> function, float radius);
	virtual ~CircleCollider();

	float GetRadius();
private:
	float m_Radius;
};
#endif
