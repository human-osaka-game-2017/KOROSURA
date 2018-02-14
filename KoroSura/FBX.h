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
		D3DVECTOR Vec;		// ���_�f�[�^
		D3DVECTOR Normal;	// �@���f�[�^
		float tu;			// �e�N�X�`�����Wx
		float tv;			// �e�N�X�`�����Wy
	};

	struct UserTexture
	{
		std::string TextureName;
		LPDIRECT3DTEXTURE9 pTexture;
	};

	struct ModelDataFBX {
		int PolygonNum;//���|���S����
		int PolygonVertexNum;//�|���S�����_�C���f�b�N�X��
		int controlNum; //���_��
		int* IndexAry;//�|���S�����_�C���f�b�N�X�z��
		D3DXVECTOR4* Positions;//���_���W�z��	
		std::vector<D3DXVECTOR3*> NormalVector;//�@���x�N�g���z��
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