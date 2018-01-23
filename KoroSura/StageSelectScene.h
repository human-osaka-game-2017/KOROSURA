/**
 * @file	StageSelectScene.h
 * @brief	StageSelectSceneクラスのヘッダ
 * @author	shiraishi
 */
#ifndef STAGESELECTSCENE_H
#define STAGESELECTSCENE_H

#include "SceneBase.h"

 /**
  * @brief		ステージセレクトシーンクラス
  * @details	SceneFactoryクラスに生成され、SceneManagerクラスに管理される。
  */
class StageSelectScene :public SceneBase{
public:
	StageSelectScene();
	virtual ~StageSelectScene();

	virtual SCENE_ID Update();
	virtual void Draw();
};
#endif