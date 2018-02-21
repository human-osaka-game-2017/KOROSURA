#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "SceneBase.h"

class MainScene :public SceneBase{
public:
	MainScene();
	virtual ~MainScene();

	//保持しているObujectBaseのUpdate関数をよんでいます
	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();
};
#endif