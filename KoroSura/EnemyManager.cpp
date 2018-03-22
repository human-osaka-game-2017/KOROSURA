#include"EnemyManager.h"
#include"EnemyBase.h"
#include"StageInfo.h"
#include"EnemyLevel.h"

EnemyManager::EnemyManager()
{
	StageInfo::StageData* pStageData = StageInfo::GetInstance().GetStageData();

	int enemyNum = 3;
	for (int i = 0; i < enemyNum; ++i) {
		EnemyBase* pEnemy = new EnemyBase(pStageData->enemyData[i].pos, D3DXVECTOR3(0.0f, 1.0f, 0.0f), pStageData->enemyData[i].level,
			static_cast<EnemyBase::ENEMY_KIND>(pStageData->enemyData[i].kind), pStageData->enemyData[i].angle, pStageData->enemyData[i].isBoss);
		m_PtrEnemys.push_back(pEnemy);
	}
}

EnemyManager::~EnemyManager()
{
	for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end(); ++ite) {
		delete *ite;
	}
}

void EnemyManager::Update()
{
	for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end();) {
		if ((*ite)->WasDead()) {
			delete *ite;
			ite = m_PtrEnemys.erase(ite);
		}
		else {
			(*ite)->Update();
			++ite;
		}
	}
}

void EnemyManager::Draw()
{
	for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end(); ++ite) {
		(*ite)->Draw();
	}
}