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
class EnemyManager;

class MainScene :public SceneBase{
public:
	MainScene();
	virtual ~MainScene();

	//�ێ����Ă���ObujectBase��Update�֐������ł��܂�
	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();

private:
	std::vector<MaterialBase*> m_PtrMaterials;
	//std::vector<ObjectBase*> m_PtrObject;
	Camera* m_pCamera;
	LimitTime* m_pLimitTime;
	EnemyManager* m_pEnemyManager;
};
#endif