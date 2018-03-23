#ifndef ENEMYLEVEL_H
#define ENEMYLEVEL_H

#include"ObjectBase.h"
#include"Utility.h"
#include"TextureManager.h"

#define FVF_3D (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

typedef struct
{
	float x, y, z;
	DWORD color;
	FLOAT	tu, tv;
} VERTEX_3D;



class EnemyLevel : public ObjectBase {
public:
	EnemyLevel(D3DXVECTOR3 pos, int level);
	virtual ~EnemyLevel();

	void SetPos(const D3DXVECTOR3& pos) { m_Pos = pos; }

	virtual void Update();

	virtual	void Draw();
	bool Draw3D(const VERTEX_3D vertex[], const char* fileName);
	VERTEX_3D* GetUV3D(const char ch, VERTEX_3D* vertex);

	void TrimingVertex(VERTEX_3D vertex[],
		float leftTopTu, float leftTopTv,
		float width, float height,
		float pngWidth, float pngHeight);

	void NextCharPos(VERTEX_3D vertex[]);

	//D3DXVECTOR3 GetPos() { return m_Pos; }
	//void SetLevel(int level) {m_Level = level; }
	//int GetLevel() { return m_Level; }
private:
	int m_Level;
	 D3DXVECTOR3 m_Pos;

};
#endif 
