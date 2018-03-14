#ifndef ENEMYLEVEL_H
#define ENEMYLEVEL_H

#include"ObjectBase.h"
#include"Utility.h"
#include"TextureManager.h"

#define FVF_3D (D3DFVF_XYZ | D3DFVF_DIFFUSE)

typedef struct
{
	float x, y, z;
	DWORD color;
	FLOAT	tu, tv;
} VERTEX_3D;



class EnemyLevel : public ObjectBase {
public:
	EnemyLevel();
	virtual ~EnemyLevel();

	virtual void Update();
	virtual void Draw();

	bool Draw3D(const VERTEX_3D vertex[], const char* fileName);

	VERTEX_3D* GetUV3D(const char ch, VERTEX_3D* vertex);

	void TrimingVertex(VERTEX_3D vertex[],
		float leftTopTu, float leftTopTv,
		float width, float height,
		float pngWidth, float pngHeight);

	void NextCharPos(VERTEX_3D vertex[]);
private:

	const D3DXVECTOR3 m_Pos;
};
#endif 
