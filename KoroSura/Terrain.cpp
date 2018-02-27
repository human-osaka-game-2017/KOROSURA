#include"Terrain.h"
#include"StageInfo.h"
#include"FBX.h"
#include"DirectGraphics.h"
#include"TextureManager.h"
#include"Lib.h"
#include"Shader.h"
#include"Effect.h"
#include"DirLightSource.h"
#include"ModelManager.h"
#include"PhysicsManager.h"

Terrain::Terrain():
	MaterialBase(D3DXVECTOR3(0.0f,0.0f,0.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f))
{
	FxManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");
	//�e�N�j�b�N�n���h���̎擾
	//Effect���Ƃɂ��΂���
	m_Technique = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetTechniqueByName("Basic");
	m_World = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "World");
}

Terrain::~Terrain() 
{
	delete[] m_TerrainData;
}

void Terrain::Draw()
{
	float* slopeDeg = PhysicsManager::GetInstance().GetSlopeDeg();

	Lib::GetInstance().TransformWorld(m_Pos,0.0f, slopeDeg[0], slopeDeg[1]);

	//�ϊ��s��̎擾
	//Effect���Ƃɂ��΂���
	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	// �萔�̐ݒ�
	//Effect���Ƃɂ��΂���
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_World, &WorldMatrix);
	// �V�F�[�_�[�p�X�̊J�n.
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\board.fbx").Draw();
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
}