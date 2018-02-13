#ifndef FBXMODEL_H
#define FBXMODEL_H

#include "FBX.h"

using std::string;
#define USERVERTEX_FVF (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1)

class FBXModel {
public:
	FBXModel() {};
	~FBXModel() {};
	void Init(char* filepath);
	void Destroy();

	void Draw();

	FBXLoader::ModelDataFBX GetFBXModelDate() { return m_FBXModelDate; }
private:
	FBXLoader::ModelDataFBX m_FBXModelDate;
	FBXLoader::UserVertex* m_Vertex;

	int m_VertexNum;
};

#endif