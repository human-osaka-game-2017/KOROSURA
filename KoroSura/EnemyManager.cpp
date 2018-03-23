#include"EnemyManager.h"
#include"EnemyBase.h"
#include"StageInfo.h"
#include"EnemyLevel.h"

EnemyManager::EnemyManager()
{
	StageInfo::StageData* pStageData = StageInfo::GetInstance().GetStageData();

	//todo pushback����Ȃ��܂Ƃ߂ėv�f���Ԃ�m�ۂ���
	int enemyNum = pStageData->enemyNum;
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

	//enemy�̃��x���\���̂��ߋ����Ń\�[�g
	{
		for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end(); ++ite) {
			(*ite)->UpdateDistance();
		}
		m_PtrEnemys.sort(EnemyBase::cmp);
	}


	for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end(); ++ite) {
		(*ite)->Draw();
	}
}