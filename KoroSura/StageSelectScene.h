/**
 * @file	StageSelectScene.h
 * @brief	StageSelectScene�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef STAGESELECTSCENE_H
#define STAGESELECTSCENE_H

#include<vector>
#include"SceneBase.h"

class Selecter;
class StageSelectBase;

 /**
  * @brief		�X�e�[�W�Z���N�g�V�[���N���X
  * @details	SceneFactory�N���X�ɐ�������ASceneManager�N���X�ɊǗ������B
  */
class StageSelectScene :public SceneBase{
public:
	StageSelectScene();
	virtual ~StageSelectScene();

	virtual SCENE_ID Update();
	virtual void Draw();

private:
	void WasSelected();

	const int kNextSceneInterval = 120;

	std::vector<StageSelectBase*> m_PtrObjects;
	Selecter* m_pSelecter;
	bool m_WasSelected = false;
	int m_FrCnt = 0;
};
#endif