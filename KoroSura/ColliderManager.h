#ifndef COLLIDERMANAGER_H
#define COLLIDERMANAGER_H

#include <vector>

class Collider;

class ColliderManager{
public:
	static ColliderManager& GetInstance();

	void Collide();

	void AddGroup();

	void DeleteGroup(int groupIndex);

	void Register(Collider* pCollider,int groupIndex);

	void Cancel(Collider* pCollider);

private:
	static ColliderManager* m_pInstance;
	ColliderManager();
	~ColliderManager();

	std::vector<std::vector<Collider*>> m_PtrColliders;
};
#endif