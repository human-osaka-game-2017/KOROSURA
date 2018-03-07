#ifndef COLLIDERMANAGER_H
#define COLLIDERMANAGER_H

#include <vector>

class ColliderBase;

//コライダーをグループに分類し、さらにフィルターをかけて判定したい奴と判定する
class ColliderManager{
public:
	static ColliderManager& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new ColliderManager;
		}
		return *m_pInstance;
	}

	//当たったやつに登録されている関数を呼んでいます
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