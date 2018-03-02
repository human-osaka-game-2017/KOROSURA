#ifndef MAINSCENE_H
#define MAINSCENE_H

#include"SceneBase.h"
#include<d3dx9.h>
#include<vector>

#include"GameClear.h"
#include"GameOver.h"

class MaterialBase;
class Camera;
class LimitTime;
class PlayerLevel;
class ObjectBase;

class MainScene :public SceneBase{
public:
	MainScene();
	virtual ~MainScene();

	//•Û‚µ‚Ä‚¢‚éObujectBase‚ÌUpdateŠÖ”‚ğ‚æ‚ñ‚Å‚¢‚Ü‚·
	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();

private:
	std::vector<MaterialBase*> m_PtrMaterials;
	std::vector<ObjectBase*> m_PtrObject;
	Camera* m_pCamera;
	LimitTime* m_pLimitTime;
	GameClear* m_pGameClear = new GameClear();
	GameOver* m_pGameOver = new GameOver();

	bool m_ClearFlg;
};
#endif