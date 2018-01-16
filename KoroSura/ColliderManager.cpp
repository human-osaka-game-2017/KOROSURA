#include"ColliderManager.h"
#include"SquareCollider.h"
#include"CircleCollider.h"
#include"Utility.h"

ColliderManager* ColliderManager::m_pInstance = nullptr;

ColliderManager& ColliderManager::GetInstance() {
	if (m_pInstance == nullptr) {
		m_pInstance = new ColliderManager;
	}
	return *m_pInstance;
}

ColliderManager::ColliderManager() {

}

ColliderManager::~ColliderManager() {

}

void ColliderManager::Update() {
	JudgeAllSquare();
	JudgeAllCircle();
}

void ColliderManager::Register(SquareCollider* pCollider) {
	m_PtrSquareColliders.push_back(pCollider);
}

void ColliderManager::Cancel(SquareCollider* pCollider) {
	for (auto itr = m_PtrSquareColliders.begin(); itr != m_PtrSquareColliders.end();) {
		if (pCollider == *itr) {
			itr = m_PtrSquareColliders.erase(itr);
		}
		else {
			itr++;
		}
	}
}

void ColliderManager::Register(CircleCollider* pCollider) {
	m_PtrCircleColliders.push_back(pCollider);
}

void ColliderManager::Cancel(CircleCollider* pCollider) {
	for (auto itr = m_PtrCircleColliders.begin(); itr != m_PtrCircleColliders.end(); ++itr){
		if (pCollider == *itr) {
			itr = m_PtrCircleColliders.erase(itr);
		}
		else {
			itr++;
		}
	}
}

void ColliderManager::JudgeAllCircle() {
	for (auto itrPoint = m_PtrCircleColliders.begin(); itrPoint != m_PtrCircleColliders.end(); ++itrPoint) {
		std::vector<std::string> collidedClassNames;
		bool isCollided = false;
		D3DXVECTOR2 pos1;
		D3DXVECTOR3 tmpPos = (*itrPoint)->GetPos();
		pos1.x = tmpPos.x;
		pos1.y = tmpPos.y;

		for (auto itr = m_PtrCircleColliders.begin(); itr != m_PtrCircleColliders.end(); ++itr) {
			if (itrPoint != itr) {
				D3DXVECTOR2 pos2;
				tmpPos = (*itr)->GetPos();
				pos2.x = tmpPos.x;
				pos2.y = tmpPos.y;

				if (Utility::JudgeCollisionCircle(pos1, (*itrPoint)->GetRadius(), pos2, (*itr)->GetRadius())) {
					isCollided = true;
					collidedClassNames.push_back((*itr)->GetAffiliatedClassName());
				}
			}
		}

		(*itrPoint)->SetCollidedClassName(collidedClassNames);

		if (isCollided) {
			(*itrPoint)->Execute();
		}
	}
}

void ColliderManager::JudgeAllSquare() {
	for (auto itrPoint = m_PtrSquareColliders.begin(); itrPoint != m_PtrSquareColliders.end(); ++itrPoint) {
		std::vector<std::string> collidedClassNames;
		bool isCollided = false;
		D3DXVECTOR2 pos1;
		D3DXVECTOR3 tmpPos = (*itrPoint)->GetPos();
		pos1.x = tmpPos.x;
		pos1.y = tmpPos.y;

		for (auto itr = m_PtrSquareColliders.begin(); itr != m_PtrSquareColliders.end(); ++itr) {
			if (itrPoint != itr) {
				D3DXVECTOR2 pos2;
				tmpPos = (*itr)->GetPos();
				pos2.x = tmpPos.x;
				pos2.y = tmpPos.y;

				if (Utility::JudgeCollisionSquare(pos1, (*itrPoint)->GetSize().width, (*itrPoint)->GetSize().height, pos2, (*itr)->GetSize().width, (*itr)->GetSize().height)) {
					isCollided = true;
					collidedClassNames.push_back((*itr)->GetAffiliatedClassName());
				}
			}
		}

		(*itrPoint)->SetCollidedClassName(collidedClassNames);

		if (isCollided) {
			(*itrPoint)->Execute();
		}
	}
}

std::vector<CircleCollider>* ColliderManager::SearchCollider(std::vector<CircleCollider>* pColliders, std::string className){
	for (auto itr = m_PtrCircleColliders.begin(); itr != m_PtrCircleColliders.end(); ++itr) {
		if ((*itr)->GetAffiliatedClassName() == className) {
			pColliders->push_back(**itr);
		}
	}
	return pColliders;
}

std::vector<SquareCollider>* ColliderManager::SearchCollider(std::vector<SquareCollider>* pColliders, std::string className) {
	for (auto itr = m_PtrSquareColliders.begin(); itr != m_PtrSquareColliders.end(); ++itr) {
		if ((*itr)->GetAffiliatedClassName() == className) {
			pColliders->push_back(**itr);
		}
	}
	return pColliders;
}