#include"SphereCollider.h"

SphereCollider::SphereCollider(const char* className, ObjectBase* pObject, Shape::Sphere* pSphere, std::function<void(std::vector<ObjectData*>*)> function,
	unsigned long categoryBits, unsigned long maskBits):
	ColliderBase(className, pObject, function, categoryBits, maskBits, Shape::SHAPE_ID::BOX),
	m_pSphere(pSphere)
{
}

SphereCollider::~SphereCollider()
{
}
