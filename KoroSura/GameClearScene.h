#ifndef GAMECLEARSCENE_H
#define GAMECLEARSCENE_H

#include "SceneBase.h"

class GameClearScene :public SceneBase{
public:
	GameClearScene();
	virtual ~GameClearScene();

	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();
};
#endif