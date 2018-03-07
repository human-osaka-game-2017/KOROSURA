#include "ColliderManager.h"
#include "ColliderBase.h"

ColliderManager* ColliderManager::m_pInstance = nullptr;

ColliderManager::ColliderManager()
{
}

ColliderManager::~ColliderManager()
{
}


void ColliderManager::Collide()
{
	for (unsigned int i = 0; i < m_PtrColliders.size(); ++i) {
		for (unsigned int j = 0; j < m_PtrColliders[i].size(); ++j) {
			std::vector<ColliderBase::ObjectData*> collidedObjects;
			for (unsigned int k = 0; k < j; ++k) {

				if ((m_PtrColliders[i][j]->GetMaskBits()&m_PtrColliders[i][k]->GetCategoryBits()) &&
					(m_PtrColliders[i][k]->GetMaskBits()&m_PtrColliders[i][j]->GetCategoryBits())) {

					if (m_PtrColliders[i][j]->Collide(*m_PtrColliders[i][k])) {
						collidedObjects.push_back(m_PtrColliders[i][k]->GetObjectData());
					}
				}
			}

			if (!collidedObjects.empty()) {
				m_PtrColliders[i][j]->Do(&collidedObjects);
			}
		}
	}
}

void ColliderManager::FormGroup()
{
	m_PtrColliders.emplace_back();
}

void ColliderManager::DeleteGroup(int groupIndex)
{
	m_PtrColliders.erase(m_PtrColliders.begin() + groupIndex);
}

void ColliderManager::Register(ColliderBase* pCollider, int groupIndex)
{
	m_PtrColliders[groupIndex].push_back(pCollider);
}

void ColliderManager::Remove(ColliderBase* pCollider)
{
	for (auto itr = m_PtrColliders.begin(); itr != m_PtrColliders.end(); ++itr) {
		for (auto itr2 = itr->begin(); itr2 != itr->end();) {
			if ((*itr2) == pCollider) {
				itr2 = itr->erase(itr2);
			}
			else {
				++itr2;
			}
		}
	}
}