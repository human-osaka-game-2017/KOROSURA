#include"SphereCollider.h"
#include"BoxCollider.h"
#include"Utility.h"

SphereCollider::SphereCollider(const char* className, ObjectBase* pObject, Shape::Sphere* pSphere, std::function<void(std::vector<ObjectData*>*)> function,
	unsigned long categoryBits, unsigned long maskBits):
	ColliderBase(className, pObject, function, categoryBits, maskBits, Shape::SHAPE_ID::BOX),
	m_pSphere(pSphere)
{
}

SphereCollider::~SphereCollider()
{
}

bool SphereCollider::Collide(const ColliderBase& collider) const
{
	bool ret;

	switch (collider.GetShapeId()) {
	case Shape::SHAPE_ID::BOX:
		ret = CollideSphereToOBB(dynamic_cast<const BoxCollider&>(collider));
		break;

	default:
		MessageBox(0, "‚»‚ÌŒ`“¯Žm‚Ì‚ ‚½‚è”»’è‚Í‚Å‚«‚Ü‚¹‚ñ", "", MB_OK);
		ret = false;
	}

	return ret;
}

bool SphereCollider::CollideSphereToOBB(const BoxCollider& collider) const
{
	bool ret;
	float distance = Utility::GetLengthOBBToPoint(collider.GetObb(), m_pSphere->GetPos());
	if (distance < m_pSphere->GetRadius()) {
		ret = true;
	}
	else {
		ret = false;
	}
	return ret;
}

bool SphereCollider::CollideSphereToSphere(const SphereCollider& collider) const
{
	return true;
}