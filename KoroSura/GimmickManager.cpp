#include"GimmickManager.h"
#include"GimmickBase.h"
#include"StageInfo.h"

GimmickManager::GimmickManager()
{
	StageInfo::StageData* pStageData = StageInfo::GetInstance().GetStageData();

	int enemyNum = pStageData->gimmickNum;
	for (int i = 0; i < enemyNum; ++i) {
		GimmickBase* pEnemy = new GimmickBase(pStageData->gimmickData[i].pos, D3DXVECTOR3(0.0f, 1.0f, 0.0f),
			static_cast<GimmickBase::GIMMICK_KIND>(pStageData->gimmickData[i].kind), pStageData->gimmickData[i].angle);
		m_PtrEnemys.push_back(pEnemy);
	}
}

GimmickManager::~GimmickManager()
{
	for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end(); ++ite) {
		delete *ite;
	}
}

void GimmickManager::Update()
{
	for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end();) {
		(*ite)->Update();
		++ite;
	}
}

void GimmickManager::Draw()
{
	for (auto ite = m_PtrEnemys.begin(); ite != m_PtrEnemys.end(); ++ite) {
		(*ite)->Draw();
	}
}