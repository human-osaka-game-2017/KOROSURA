#ifndef TITLESCENE_H
#define TITLESCENE_H

#include <vector>
#include "SceneBase.h"

class ObjectBase;

class TitleScene :public SceneBase{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual SCENE_ID Update();
	virtual void Draw();

private:
	std::vector<ObjectBase*> m_PtrObjects;
	int m_FrCnt = 0;
	bool m_WasPushedKey = false;
	bool m_CanPushKey = false;

	void CanPushKey();
	void WasPushedKey();

	const int kNextSceneInterval = 120;
};
#endif