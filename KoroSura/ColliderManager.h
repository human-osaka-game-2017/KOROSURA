#ifndef COLLIDERMANAGER_H
#define COLLIDERMANAGER_H

#include <vector>

class ColliderBase;

class ColliderManager{
public:
	static ColliderManager& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new ColliderManager;
		}
		return *m_pInstance;
	}

	void Collide();

	void FormGroup();

	void DeleteGroup(int groupIndex);

	void Register(ColliderBase* pCollider,int groupIndex);

	void Remove(ColliderBase* pCollider);

private:
	static ColliderManager* m_pInstance;
	ColliderManager();
	~ColliderManager();

	std::vector<std::vector<ColliderBase*>> m_PtrColliders;
};
#endif