/**
 * @file	StageSelectBase.h
 * @brief	StageSelectBaseヘッダ
 * @author	shiraishi
 */
#ifndef STAGESELECTBASE_H
#define STAGESELECTBASE_H

#include"ObjectBase.h"

 /**
  * @brief		ステージセレクトシーンで使われるクラスが継承する基底クラス
  * @details	選択されているステージ番号をStageSelectSceneクラスにセットしてもらう
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