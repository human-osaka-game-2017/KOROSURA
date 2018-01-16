#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include "SceneBase.h"

class ResultScene :public SceneBase{
public:
	ResultScene();
	virtual ~ResultScene();

	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();
};
#endif