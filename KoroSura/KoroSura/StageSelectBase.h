/**
 * @file	StageSelectBase.h
 * @brief	StageSelectBase�w�b�_
 * @author	shiraishi
 */
#ifndef STAGESELECTBASE_H
#define STAGESELECTBASE_H

#include"ObjectBase.h"

 /**
  * @brief		�X�e�[�W�Z���N�g�V�[���Ŏg����N���X���p��������N���X
  * @details	�I������Ă���X�e�[�W�ԍ���StageSelectScene�N���X�ɃZ�b�g���Ă��炤
  */
class StageSelectBase :public ObjectBase {
public:
	StageSelectBase(){}
	virtual ~StageSelectBase(){}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetSelectPoint(int selectPoint)
	{
		m_SelectPoint = selectPoint;
	}

protected:
	int m_SelectPoint;
};
#endif