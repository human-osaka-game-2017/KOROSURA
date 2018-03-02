#include"Slime.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"ModelManager.h"
#include"Physics.h"
#include"PhysicsManager.h"
#include"EffectManager.h"
#include"SphereCollider.h"
#include"InitProperty.h"
#include"Common.h"
#include"ColliderManager.h"

Slime::Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level):
	CharacterBase(pos, normalVec, level),
	kInitialPos(pos)
{
	m_Pos.y += InitProperty::GetInstance().GetInitialData().slimeInitialData.modelOffset;
	m_Sphere.SetPos(InitProperty::GetInstance().GetInitialData().slimeInitialData.colliderOffset + m_Pos);
	m_Sphere.SetRadius(InitProperty::GetInstance().GetInitialData().slimeInitialData.radius);
	m_pCollider = new SphereCollider("Slime", this, &m_Sphere, std::bind(&Slime::Collided, this, std::placeholders::_1),
		CATEGORY_BITS_SLIME, FOURBITE_ALLBITS);
	ColliderManager::GetInstance().Register(m_pCollider, 0);

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
	if (rollVec == D3DXVECTOR3(0.0f, 0.0f, 0.0f))acceleration = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	acceleration += rollVec;
	m_Pos = acceleration + (currentOnBoardPos);

	m_PosXZ.x += acceleration.x;
	m_PosXZ.z += acceleration.z;

	m_IsFall = true;
}

void Slime::Draw()
{
	Lib::GetInstance().TransformWorld(m_Pos);

	D3DXMATRIX WorldMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->SetWorldMatrix(&WorldMatrix);

	// シェーダーパスの開始.
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
	ModelManager::GetInstance().GetFBXDate("FBX\\FBXModel\\slime.fbx").Draw();
	EffectManager::GetpInstance().GetEffect("Shader\\BasicShader.fx")->EndPass();
}

void Slime::Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects)
{
	for (auto ite = collidedObjects->begin(); ite != collidedObjects->end(); ++ite) {

		if ((*ite)->ClassName == std::string("Terrain")) {
			m_IsFall = false;
		}

		if ((*ite)->ClassName == std::string("EnemyBase")) {
			EnemyBase* pEnemy = dynamic_cast<EnemyBase*>((*ite)->pObject);

			if (m_Level >= pEnemy->GetLevel()) {
				if (m_Level - pEnemy->GetLevel() < 3) {
					++m_Level;
				}
			}
		}
	}
}