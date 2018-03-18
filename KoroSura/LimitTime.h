#ifndef LIMITTIME_H
#define LIMITTIME_H

#include"ObjectBase.h"
#include"Utility.h"
#include"SceneBase.h"
#include<functional>

class LimitTime : public ObjectBase 
{
public:
	LimitTime(std::function<void(SceneBase::SCENE_ID)>, int limit_s);
	virtual ~LimitTime();

	virtual void Update();

	virtual void Draw();
private:
	void NextCharPos(Utility::CUSTOMVERTEX vertex[]);
	const D3DXVECTOR2 m_Pos;

	std::function<void(SceneBase::SCENE_ID)> m_Function;
	unsigned int m_FrCnt = 0;

	int m_Limit_s = 0;
	//todo rename
	bool m_CanWatched = true;
};

#endif