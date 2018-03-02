/**
 * @file	StageLogo.h
 * @brief	StageLogo�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef STAGELOGO_H
#define STAGELOGO_H

#include"StageSelectBase.h"
#include"Utility.h"

class Enlarger;

 /**
  * @brief		�e�X�e�[�W�ԍ���\������N���X
  * @details	�I������Ă���X�e�[�W�ԍ����g��A�X���C���J�[�\����\��
  */
class StageLogo :public StageSelectBase{
public:
	StageLogo();
	virtual ~StageLogo();

	virtual void Update();
	virtual void Draw();

private:
	void DrawStageFonts(int num);
	void NextCharPos(Utility::CUSTOMVERTEX vertex[]);

	//Stage1��'S'�̒��S���W
	const D3DXVECTOR2 m_Pos;

	const int kFontWidth	= 33;
	const int kFontHeight	= 98;
	//const int kFrameWidth	= 200;
	//const int kFrameHeight	= 100;
	const int kFrameWidth = 350;
	const int kFrameHeight = 100;
};
#endif