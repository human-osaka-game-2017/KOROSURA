#include"CircleCollider.h"

CircleCollider::CircleCollider(const std::string className, const D3DXVECTOR3& pos, std::function<void()> function, float radius):
	ColliderBase(className,pos,function),
	m_Radius(radius)
{

}

CircleCollider::~CircleCollider() {

}

float CircleCollider::GetRadius() {
	return m_Radius;
}