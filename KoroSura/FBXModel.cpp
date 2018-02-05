#include "FBXModel.h"
#include "DirectGraphics.h"

void FBXModel::Init(char* filepath)
{
	FBXLoader::FBXGetInstance().FBXLoad(&m_FBXModelDate,filepath);
	m_VertexNum = m_FBXModelDate.PolygonNum / 3;
	m_Vertex = new FBXLoader::UserVertex[m_FBXModelDate.PolygonVertexNum];
	for (int i = 0; i < m_FBXModelDate.PolygonVertexNum; i++) {
		D3DVECTOR tmpPos;
		tmpPos.x = m_FBXModelDate.Positions[m_FBXModelDate.IndexAry[i]].x;
		tmpPos.y = m_FBXModelDate.Positions[m_FBXModelDate.IndexAry[i]].y;
		tmpPos.z = m_FBXModelDate.Positions[m_FBXModelDate.IndexAry[i]].z;
		D3DVECTOR tmpNormal;
		/*tmpNormal.x = m_FBXModelDate.NormalVector[i]->x;
		tmpNormal.y = m_FBXModelDate.NormalVector[i]->y;
		tmpNormal.z = m_FBXModelDate.NormalVector[i]->z;*/
		m_Vertex[i].Vec.x = tmpPos.x;
		m_Vertex[i].Vec.y = tmpPos.y;
		m_Vertex[i].Vec.z = tmpPos.z;
	/*	m_Vertex[i].Normal.x = tmpNormal.x;
		m_Vertex[i].Normal.y = tmpNormal.y;
		m_Vertex[i].Normal.z = tmpNormal.z;*/
		m_Vertex[i].tu = m_FBXModelDate.uvBuffer[i].x;
		m_Vertex[i].tv = m_FBXModelDate.uvBuffer[i].y;
	}
}

void FBXModel::Destroy()
{
	delete[] m_Vertex;
}

void FBXModel::Draw()
{
	///@todo fvf‚ÌÝ’è‚Í•ª‚¯‚Æ‚«‚½‚¢‚©‚È
	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(USERVERTEX_FVF);

	(*DirectGraphics::GetInstance().GetDevice())->SetTexture(0, NULL);

	(*DirectGraphics::GetInstance().GetDevice())->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		m_FBXModelDate.PolygonNum,
		m_Vertex,
		sizeof(FBXLoader::UserVertex));
}