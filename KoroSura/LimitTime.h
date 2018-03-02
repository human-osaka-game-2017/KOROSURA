#ifndef LIMITTIME_H
#define LIMITTIME_H

#include"ObjectBase.h"
#include"Utility.h"
#include"SceneBase.h"
#include<functional>

class LimitTime : public ObjectBase 
{
public:
	LimitTime(std::function<void(SceneBase::SCENE_ID)>);
	virtual ~LimitTime();

	virtual void Update();

	virtual void Draw();
private:
	void NextCharPos(Utility::CUSTOMVERTEX vertex[]);
	const D3DXVECTOR2 m_Pos;

	std::function<void(SceneBase::SCENE_ID)> m_Function;
	unsigned int m_FrCnt = 0;

	//todo rename
	int m_TenNum = 6;
	int m_OneNum = 0;
};

#endif