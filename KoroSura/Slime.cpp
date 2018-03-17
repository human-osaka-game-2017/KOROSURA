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
#include"PlayerLevel.h"
#include"StageInfo.h"
#include"BoxCollider.h"

Slime::Slime(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, int level, std::function<void(SceneBase::SCENE_ID)> function):
	CharacterBase(pos, normalVec, level),
	kInitialPos(pos),
	m_Function(function)
{
	m_Pos.y += InitProperty::GetInstance().GetInitialData().slimeInitialData.modelOffset;
	m_Sphere.SetPos(InitProperty::GetInstance().GetInitialData().slimeInitialData.colliderOffset + m_Pos);
	m_Sphere.SetRadius(InitProperty::GetInstance().GetInitialData().slimeInitialData.radius);
	m_pPlayerLevel = new PlayerLevel();
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
	m_pPlayerLevel->Update();
	D3DXVECTOR3 boardSize = StageInfo::GetInstance().GetStageData()->mapSize;

	if (-boardSize.x / 2 < m_PosXZ.x&&m_PosXZ.x < boardSize.x / 2 &&
		-boardSize.z / 2 < m_PosXZ.z&&m_PosXZ.z < boardSize.z / 2) {

		D3DXVECTOR3 currentOnBoardPos = m_PosXZ;
		PhysicsManager::GetInstance().TranceformOnBoard(currentOnBoardPos, &currentOnBoardPos);
		currentOnBoardPos.y += kInitialPos.y;

		D3DXVECTOR3 rollVec;
		m_pPhysics->GetRollVec(&rollVec);
		float length = m_pPhysics->GetRollVelocity();
		rollVec *= length;

		if (rollVec == D3DXVECTOR3(0.0f, 0.0f, 0.0f))m_Acceleration = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Acceleration += rollVec;

		m_Pos = m_Acceleration + (currentOnBoardPos);
	}
	else {
		m_Acceleration += PhysicsManager::GetInstance().GetGravity();
		m_Pos += m_Acceleration;

		if (m_Pos.y < -1000) {
			m_Function(SceneBase::SCENE_ID::GAMEOVER);
		}
	}

	m_Sphere.SetPos(m_Pos);

	m_PosXZ.x += m_Acceleration.x;
	m_PosXZ.z += m_Acceleration.z;
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
	m_pPlayerLevel->Draw(m_Level);
	DirectGraphics::GetInstance().SetRenderState3D();
	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(USERVERTEX_FVF);
}

void Slime::Collided(std::vector<ColliderBase::ObjectData*>* collidedObjects)
{
	for (auto ite = collidedObjects->begin(); ite != collidedObjects->end(); ++ite) {

		if ((*ite)->ClassName == std::string("GimmickBase")) {
			GimmickBase* pGimmick = dynamic_cast<GimmickBase*>((*ite)->pObject);
			D3DXVECTOR3 extrusionVec;
			Utility::VecOBBToPoint(pGimmick->GetCollider()->GetObb(), m_Pos, &extrusionVec);

			D3DXVECTOR3 radiusVec;
			D3DXVec3Normalize(&radiusVec, &extrusionVec);
			radiusVec *= m_Sphere.GetRadius();

			D3DXVECTOR3 distance = radiusVec - extrusionVec;

			m_Acceleration = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_Pos += distance;
			m_PosXZ += distance;
			m_PosXZ.y = 0;
		}

		if ((*ite)->ClassName == std::string("EnemyBase")) {
			EnemyBase* pEnemy = dynamic_cast<EnemyBase*>((*ite)->pObject);

			if (m_Level >= pEnemy->GetLevel()) {
				if (m_Level - pEnemy->GetLevel() < 3) {
					++m_Level;
				}
				if (pEnemy->IsBoss()) {
					m_Function(SceneBase::SCENE_ID::GAMECLEAR);
				}

				pEnemy->Dead();
			}

			//押し出し処理
			else {
				D3DXVECTOR3 extrusionVec;
				Utility::VecOBBToPoint(pEnemy->GetCollider()->GetObb(), m_Pos, &extrusionVec);

				D3DXVECTOR3 radiusVec;
				D3DXVec3Normalize(&radiusVec, &extrusionVec);
				radiusVec *= m_Sphere.GetRadius();

				D3DXVECTOR3 distance = radiusVec - extrusionVec;

				m_Acceleration = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				m_Pos += distance;
				m_PosXZ += distance;
				m_PosXZ.y = 0;
			}
		}
	}
}