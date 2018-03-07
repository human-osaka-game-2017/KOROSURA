/**
 * @file	StageSelectBackground.h
 * @brief	StageSelectBackgroundクラスのヘッダ
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