#ifndef COLLIDERBASE_H
#define COLLIDERBASE_H

#include<functional>
#include<string>
#include"Shape.h"

class ObjectBase;

class ColliderBase{
public:
	struct ObjectData {
		ObjectData(std::string className, ObjectBase* pArgObject):
			ClassName(className),
			pObject(pArgObject){}

		const std::string ClassName;

		//çDÇ´Ç»ç\ë¢ëÃÇçÏÇ¡ÇƒãlÇﬂÇÈ
		ObjectBase* pObject;
	};

	ColliderBase(const char* className, ObjectBase* pObject, std::function<void(ObjectData[])> function, unsigned long categoryBits, unsigned long maskBits, Shape::SHAPE_ID shapeId);
	virtual ~ColliderBase() {};

	Shape::SHAPE_ID GetShapeId();

	void SetMaskBits(unsigned long maskBits);

	virtual bool Collide(const ColliderBase& collider) = 0;

private:
	ObjectData m_ObjectData;
	std::function<void(ObjectData[])> m_Function;
	unsigned long m_MaskBits;

	const unsigned long kCategoryBits;
	const Shape::SHAPE_ID kShapeId;
};
#endif