#include"Slime.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"Shader.h"
#include"Effect.h"
#include"DirLightSource.h"
#include"ModelManager.h"
#include"Physics.h"

Slime::Slime(D3DXVECTOR3& pos):
	CharacterBase(pos)
{
	FxManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");
	//�e�N�j�b�N�n���h���̎擾
	//Effect���Ƃɂ��΂���
	m_Technique = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetTechniqueByName("Basic");
	m_World = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "World");
	m_View = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "View");
	m_Proj = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Proj");
	m_Light = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Light");

	m_pPhysics = new Physics();
}

Slime::~Slime()
{
}

void Slime::Update()
{
	D3DXVECTOR3 rollVec;
	m_pPhysics->GetRollVec(&rollVec, m_Pos);
	rollVec *= m_pPhysics->GetRollVelocity();

	m_Pos += rollVec;

	Lib::GetInstance().TransformWorld(m_Pos);
}

void Slime::Draw()
{
	//�ϊ��s��̎擾
	//Effect���Ƃɂ��΂���
	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	//Effect���Ƃɂ��΂���
	D3DXMATRIX WorldMatrix2;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix2);
	D3DXMATRIX ViewMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	D3DXMATRIX ProjMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);
	// �萔�̐ݒ�
	//Effect���Ƃɂ��΂���
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_World, &WorldMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_World, &WorldMatrix2);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_View, &ViewMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_Proj, &ProjMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetVector(m_Light, &DirLightSource::GetpInstance().GetlightDir());
	// �V�F�[�_�[�p�X�̊J�n.
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\sky.fbx").Draw();
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();

	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\fence.fbx").Draw();
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
}