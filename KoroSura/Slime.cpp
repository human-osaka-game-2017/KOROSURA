#include"Slime.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"ModelManager.h"
#include"Physics.h"
#include"PhysicsManager.h"
#include"EffectManager.h"

Slime::Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level):
	CharacterBase(pos, normalVec, level),
	kInitialPos(pos)
{
	m_pPhysics = new Physics();
}

Slime::~Slime()
{
	delete m_pPhysics;
}

void Slime::Update()
{
	D3DXVECTOR3 currentOnBoardPos;
	currentOnBoardPos = m_PosXZ;
	PhysicsManager::GetInstance().TranceformOnBoard(currentOnBoardPos, &currentOnBoardPos);

	D3DXVECTOR3 rollVec;
	m_pPhysics->GetRollVec(&rollVec);
	float length = m_pPhysics->GetRollVelocity();
	rollVec *= length;

	m_Pos = rollVec + (currentOnBoardPos);

	m_PosXZ.x += rollVec.x;
	m_PosXZ.z += rollVec.z;
}

void Slime::DrawPreparation()
{

}

void Slime::Draw()
{
	Lib::GetInstance().TransformWorld(m_Pos);

	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&WorldMatrix);

	// シェーダーパスの開始.
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\fence.fbx").Draw();
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}