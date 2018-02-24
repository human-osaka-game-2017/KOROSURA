#include"Terrain.h"
#include"StageInfo.h"
#include"FBX.h"
#include"DirectGraphics.h"
#include"TextureManager.h"
#include"Lib.h"

Terrain::Terrain()
{
	Lib::GetInstance().LoadPictureFile("Picture\\ground1.png", 256, 256);

	//m_TerrainData = StageInfo::GetInstance().GetStageData()->terrainData;
	m_TerrainData = new int[800]{ 1 };
}

Terrain::~Terrain() 
{
	delete[] m_TerrainData;
}

void Terrain::Draw()
{
	//D3DXVECTOR3 pos = {0.0f,0.0f,0.0f};

	//Lib::GetInstance().TransformWorld(pos);

	//FBXLoader::UserVertex vertex[12]=
	//{
	//	{ D3DVECTOR{ -kSize / 2, +kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 },
	//	{ D3DVECTOR{ +kSize / 2, +kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },1.0,0.0 },
	//	{ D3DVECTOR{ +kSize / 2, -kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },1.0,1.0 },
	//	{ D3DVECTOR{ +kSize / 2, -kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,1.0 },
	//	{ D3DVECTOR{ -kSize / 2, -kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 },
	//	{ D3DVECTOR{ -kSize / 2, +kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },1.0,0.0 },
	//	{ D3DVECTOR{ -kSize / 2, +kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 },
	//	{ D3DVECTOR{ +kSize / 2, +kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 },
	//	{ D3DVECTOR{ +kSize / 2, +kSize / 2, +kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 },
	//	{ D3DVECTOR{ +kSize / 2, +kSize / 2, +kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 },
	//	{ D3DVECTOR{ -kSize / 2, +kSize / 2, +kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 },
	//	{ D3DVECTOR{ -kSize / 2, +kSize / 2, -kSize / 2 },D3DVECTOR{ 0.0f,1.0f,0.0f },0.0,0.0 }

	//};

	//(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1);

	//	(*DirectGraphics::GetInstance().GetDevice())->
	//		SetTexture(0, TextureManager::GetInstance().GetPictureInfo("Picture\\ground1.png").texture);

	//(*DirectGraphics::GetInstance().GetDevice())->DrawPrimitiveUP(
	//	D3DPT_TRIANGLELIST,
	//	4,
	//	vertex,
	//	sizeof(FBXLoader::UserVertex));
}