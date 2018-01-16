#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "SceneBase.h"

class TitleScene :public SceneBase{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual SCENE_ID Update();
	virtual void Draw();

private:
	int m_FrCnt = 0;
	bool m_WasPushedKey = false;

	const int kNextSceneInterval = 180;
};
#endif