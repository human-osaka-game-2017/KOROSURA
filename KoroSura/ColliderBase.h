/**
 * @file	ColliderBase.h
 * @brief	簡単なクラスの説明
 * @author	作成者の名前
 */
#ifndef COLLIDERBASE_H
#define COLLIDERBASE_H

#include <functional>
#include <string>
#include <vector>
#include "Shape.h"

class ObjectBase;

class ColliderBase{
public:
	struct ObjectData {
		ObjectData(std::string className, ObjectBase* pArgObject):
			ClassName(className),
			pObject(pArgObject){}

		const std::string ClassName;

		ObjectBase* pObject;
	};

	ColliderBase(const char* className, ObjectBase* pObject, std::function<void(std::vector<ObjectData*>*)> function, unsigned long categoryBits, unsigned long maskBits, Shape::SHAPE_ID shapeId);
	virtual ~ColliderBase() {};

	Shape::SHAPE_ID GetShapeId() const 
	{
		return kShapeId;
	}

	unsigned long GetMaskBits()
	{
		return m_MaskBits;
	}

	void SetMaskBits(unsigned long maskBits)
	{
		m_MaskBits = maskBits;
	}

	unsigned long GetCategoryBits()
	{
		return kCategoryBits;
	}

	ObjectData* GetObjectData()
	{
		return &m_ObjectData;
	}

	void Do(std::vector<ObjectData*>* collidedObjects)
	{
		m_Function(collidedObjects);
	}

	virtual bool Collide(const ColliderBase& collider)const = 0;

private:
	ObjectData m_ObjectData;
	std::function<void(std::vector<ObjectData*>*)> m_Function;
	unsigned long m_MaskBits;

	const unsigned long kCategoryBits;
	const Shape::SHAPE_ID kShapeId;
};
#endif