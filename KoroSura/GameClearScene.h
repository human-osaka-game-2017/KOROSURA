#ifndef GAMECLEARSCENE_H
#define GAMECLEARSCENE_H

#include"SceneBase.h"
#include"GameClear.h"

class GameClearScene :public SceneBase{
public:
	GameClearScene();
	virtual ~GameClearScene();

	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();
private:
	GameClear* m_pGameClear;
};
#endif