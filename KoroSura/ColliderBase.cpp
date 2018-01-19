#include"ColliderBase.h"
#include"ObjectBase.h"

ColliderBase::ColliderBase(const char* className, ObjectBase* pObject, std::function<void(ObjectData[])> function, unsigned long categoryBits, unsigned long maskBits, Shape::SHAPE_ID shapeId):
	m_ObjectData(className,pObject), m_Function(function), kCategoryBits(categoryBits), m_MaskBits(maskBits), kShapeId(shapeId)
{

}

Shape::SHAPE_ID ColliderBase::GetShapeId()
{
	return kShapeId;
}

void ColliderBase::SetMaskBits(unsigned long maskBits) 
{

}