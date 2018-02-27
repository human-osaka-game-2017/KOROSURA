#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include<map>
#include<d3dx9.h>

#include"FBXModel.h"

using std::string;

class ModelManager {
public:
	static void CreateInstance();
	static ModelManager& GetInstance();

	struct ModelData {
		LPD3DXMESH pMesh = NULL;
		DWORD DwNumMaterials = 0;
		D3DMATERIAL9* pMeshMaterials = NULL;
		LPDIRECT3DTEXTURE9* pMeshTextures = NULL;
	};

	//メッシュを消します
	void CancelMesh(const char* fileName);

	//Xファイルからデータを読み込みます
	//第一引数 ファイルへのパス
	HRESULT LoadXFile(const char* fileName);

	HRESULT LoadFBXFile(char* fileName);

	FBXModel& GetFBXDate(char* fileName){return m_FBXDate[fileName];}

	void Draw(const char* fileName);

private:
	static ModelManager* pInstance;
	ModelManager();
	~ModelManager();

	std::map<string, ModelData> m_MeshData;

	std::map<string, FBXModel> m_FBXDate;

	ModelManager(const ModelManager&);
	void operator =(const ModelManager&);

public:
	const ModelData& GetModelData(const char* fileName) {
		if (m_MeshData.find(fileName) != m_MeshData.end()) {
			return m_MeshData[fileName];
		}
		exit(1);
	}
};
#endif