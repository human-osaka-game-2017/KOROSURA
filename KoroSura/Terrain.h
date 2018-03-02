#ifndef TERRAIN_H
#define TERRAIN_H

#include"MaterialBase.h"
#include"Shape.h"
#include"ColliderBase.h"
#include<vector>

class BoxCollider;

class Terrain :public MaterialBase{
public:
	Terrain();
	virtual ~Terrain();

	virtual void Update();
	virtual void Draw();

private:
	void Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects);

	const float kSize = 200.0f;

	Shape::OBB m_OBB;
	BoxCollider* m_pCollider;
	//int* m_TerrainData;
};
#endif