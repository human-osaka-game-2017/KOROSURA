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
	currentOnBoardPos.y += kInitialPos.y;

	D3DXVECTOR3 rollVec;
	m_pPhysics->GetRollVec(&rollVec);
	float length = m_pPhysics->GetRollVelocity();
	rollVec *= length;
	Utility::OutputDebug_Number(length);

	static D3DXVECTOR3 acceleration = rollVec;
	acceleration += rollVec;
	m_Pos = acceleration + (currentOnBoardPos);

	m_PosXZ.x += acceleration.x;
	m_PosXZ.z += acceleration.z;
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
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\ball.fbx").Draw();
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}