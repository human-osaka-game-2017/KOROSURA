#ifndef MAINSCENE_H
#define MAINSCENE_H

#include"SceneBase.h"
#include<d3dx9.h>
#include<vector>

class MaterialBase;
class Camera;
class LimitTime;
class PlayerLevel;

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

	bool m_ClearFlg;
};
#endif