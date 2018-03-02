#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include"SceneBase.h"
#include"GameOver.h"

class GameOverScene : public SceneBase{
public:
	GameOverScene();
	virtual ~GameOverScene();

	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();
private:
	GameOver* m_pGameOver;
};

#endif