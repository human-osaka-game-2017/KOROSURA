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
	D3DXVECTOR3 rollVec;
	static D3DXVECTOR3 prevPos = kInitialPos;
	static D3DXVECTOR3 prevVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_pPhysics->GetRollVec(&rollVec);

	static float prevLength = D3DXVec3Length(&kInitialPos);
	D3DXVECTOR3 currentOnBoardPos;
	if (rollVec != prevVec) {
		currentOnBoardPos = rollVec*prevLength;
	}
	else {
		currentOnBoardPos = m_Pos;
	}

	float length = m_pPhysics->GetRollVelocity();
	rollVec *= length;
	//rollVec += prevVec;

	m_Pos = rollVec + (currentOnBoardPos);

	prevVec = rollVec;
	prevLength = D3DXVec3Length(&m_Pos);
	prevPos = m_Pos;

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