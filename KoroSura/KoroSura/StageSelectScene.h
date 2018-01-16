#ifndef STAGESELECTSCENE_H
#define STAGESELECTSCENE_H

#include "SceneBase.h"

class StageSelectScene :public SceneBase{
public:
	StageSelectScene();
	virtual ~StageSelectScene();

	virtual SCENE_ID Update();
	virtual void Draw();
};
#endif