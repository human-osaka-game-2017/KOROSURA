/**
 * @file	StageSelectBackground.h
 * @brief	StageSelectBackground�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef STAGESELECTBACKGROUND_H
#define STAGESELECTBACKGROUND_H

#include"StageSelectBase.h"

class StageSelectBackground: public StageSelectBase{
public:
	StageSelectBackground();
	virtual ~StageSelectBackground();

	virtual void Update();
	virtual void Draw();
};
#endif