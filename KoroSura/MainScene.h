#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "SceneBase.h"

class MainScene :public SceneBase{
public:
	MainScene();
	virtual ~MainScene();

	//�ێ����Ă���ObujectBase��Update�֐������ł��܂�
	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();
};
#endif