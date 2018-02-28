#ifndef MAINSCENE_H
#define MAINSCENE_H

#include"SceneBase.h"
#include<d3dx9.h>
#include<vector>

class MaterialBase;
class Camera;

class MainScene :public SceneBase{
public:
	MainScene();
	virtual ~MainScene();

	//•Û‚µ‚Ä‚¢‚éObujectBase‚ÌUpdateŠÖ”‚ğ‚æ‚ñ‚Å‚¢‚Ü‚·
	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();

private:
	std::vector<MaterialBase*> m_PtrMaterials;
	Camera* m_pCamera;
};
#endif