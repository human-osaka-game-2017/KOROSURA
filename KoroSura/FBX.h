#ifndef FBX_H
#define FBX_H

#include <fbxsdk.h>
#include<iostream>
#include<d3dx9.h>
#include<vector>
#include<string>
#include<list>
#include <map>


class FBXLoader {
public:
	struct Color_RGB {
		float red, green, blue;
	};

	struct UserVertex
	{
		D3DVECTOR Vec;		// 頂点データ
		D3DVECTOR Normal;	// 法線データ
		float tu;			// テクスチャ座標x
		float tv;			// テクスチャ座標y
	};

	struct UserTexture
	{
		std::string TextureName;
		LPDIRECT3DTEXTURE9 pTexture;
	};

	struct ModelDataFBX {
		int PolygonNum;//総ポリゴン数
		int PolygonVertexNum;//ポリゴン頂点インデックス数
		int controlNum; //頂点数
		int* IndexAry;//ポリゴン頂点インデックス配列
		D3DXVECTOR4* Positions;//頂点座標配列	
		std::vector<D3DXVECTOR3*> NormalVector;//法線ベクトル配列
		std::vector<std::string> uvSetName;
		std::vector<UserTexture> textures;
		std::vector<D3DXVECTOR2> uvBuffer;
		int MaterialCount;
		Color_RGB Ambient;
		Color_RGB Diffuse;
	};

	static void CreateFBXInstance();
	static FBXLoader& FBXGetInstance();

	void GetTextureNames(
		FbxSurfaceLambert* lambert,
		const FbxProperty& prop,
		ModelDataFBX* pMeshData);

	void GetTexture(FbxMesh* pMesh, ModelDataFBX* pMeshData);

	void GetVertexUV(FbxMesh* pMesh, ModelDataFBX* pMeshData);

	void GetVertexNormal(FbxMesh* pMesh, ModelDataFBX* pMeshData);

	void GetPosition(FbxMesh* pMesh, ModelDataFBX* pMeshData);

	void GetMesh(FbxNode* node, ModelDataFBX* pMeshData);

	void FBXLoad(ModelDataFBX* pMeshData, char* filepath);

private:
	FBXLoader() {};
	~FBXLoader() {};

	static FBXLoader* FBXpInstance;
};
#endif