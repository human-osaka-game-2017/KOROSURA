#include"ModelManager.h"
#include"DirectGraphics.h"

ModelManager* ModelManager::pInstance = nullptr;

void ModelManager::CreateInstance() {
	if (pInstance == nullptr) {
		pInstance = new ModelManager();
	}
}

ModelManager& ModelManager::GetInstance() {
	if (pInstance == nullptr) {
		MessageBox(0, "ModelManager�C���X�^���X����������Ă��܂���", "", MB_OK);
	}
	return *pInstance;
}

ModelManager::ModelManager() {
}

ModelManager::~ModelManager() {
	for (auto itr = m_MeshData.begin(); itr != m_MeshData.end(); itr++)
	{
		delete itr->second.pMeshMaterials;
		delete itr->second.pMeshTextures;
		SAFE_RELEASE(itr->second.pMesh);
	}

	delete pInstance;
}

HRESULT ModelManager::LoadXFile(const char* fileName) {
	LPDIRECT3DDEVICE9* pDXDevice = DirectGraphics::GetInstance().GetDevice();

	// X�t�@�C�����烁�b�V�������[�h����	
	LPD3DXBUFFER pD3DXMtrlBuffer = NULL;

	if (FAILED(D3DXLoadMeshFromX(fileName, D3DXMESH_SYSTEMMEM,
		*pDXDevice, NULL, &pD3DXMtrlBuffer, NULL,
		&m_MeshData[fileName].DwNumMaterials, &m_MeshData[fileName].pMesh)))
	{
		MessageBox(NULL, "X�t�@�C���̓ǂݍ��݂Ɏ��s���܂���", NULL, MB_OK);
		return E_FAIL;
	}
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();
	m_MeshData[fileName].pMeshMaterials = new D3DMATERIAL9[m_MeshData[fileName].DwNumMaterials];
	m_MeshData[fileName].pMeshTextures = new LPDIRECT3DTEXTURE9[m_MeshData[fileName].DwNumMaterials];

	for (DWORD i = 0; i < m_MeshData[fileName].DwNumMaterials; i++)
	{
		m_MeshData[fileName].pMeshMaterials[i] = d3dxMaterials[i].MatD3D;
		m_MeshData[fileName].pMeshMaterials[i].Ambient = m_MeshData[fileName].pMeshMaterials[i].Diffuse;
		m_MeshData[fileName].pMeshTextures[i] = NULL;
		if (d3dxMaterials[i].pTextureFilename != NULL &&
			lstrlen(d3dxMaterials[i].pTextureFilename) > 0)
		{
			if (FAILED(D3DXCreateTextureFromFile(*pDXDevice,
				d3dxMaterials[i].pTextureFilename,
				&m_MeshData[fileName].pMeshTextures[i])))
			{
				MessageBox(NULL, "�e�N�X�`���̓ǂݍ��݂Ɏ��s���܂���", NULL, MB_OK);
			}
		}
	}
	pD3DXMtrlBuffer->Release();

	return S_OK;
}

void ModelManager::CancelMesh(const char* fileName) {
	delete m_MeshData[fileName].pMeshMaterials;
	delete m_MeshData[fileName].pMeshTextures;
	SAFE_RELEASE(m_MeshData[fileName].pMesh);
	m_MeshData.erase(fileName);
}