#ifndef TERRAIN_H
#define TERRAIN_H

#include"MaterialBase.h"

class Terrain :public MaterialBase{
public:
	Terrain();
	virtual ~Terrain();

	virtual void Update();
	virtual void DrawPreparation();
	virtual void Draw();

private:
	const float kSize = 200.0f;

	int* m_TerrainData;
};
#endif