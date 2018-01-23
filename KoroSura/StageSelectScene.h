/**
 * @file	StageSelectScene.h
 * @brief	StageSelectScene�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef STAGESELECTSCENE_H
#define STAGESELECTSCENE_H

#include "SceneBase.h"

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
};
#endif