#ifndef GIMMICKMANAGER_H
#define GIMMICKMANAGER_H

#include<vector>
#include"ObjectBase.h"

class GimmickBase;

class GimmickManager :public ObjectBase {
public:
	GimmickManager();
	virtual ~GimmickManager();

	virtual void Update();
	virtual void Draw();

private:
	std::vector<GimmickBase*> m_PtrEnemys;
};
#endif
