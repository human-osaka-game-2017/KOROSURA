/**
 * @file	Description.h
 * @brief	Descriptionクラスのヘッダ
 * @author	shiraishi
 */
#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include"StageSelectBase.h"
#include<d3dx9.h>

class Enlarger;

 /**
  * @brief		選択されているステージのイメージ画像と説明を表示するクラス
  * @details	StageSelectSceneクラスに生成される
  */
class Description :public StageSelectBase {
public:
	Description();
	virtual ~Description();

	virtual void Update();
	virtual void Draw();

private:
	float GetLeftTopTu();

	const int kPngWidth		= 8192;
	const int kPngHeight	= 1024;

	const D3DXVECTOR2 kStagePicPos = D3DXVECTOR2(1000.0f, 350.0f);
	const D3DXVECTOR2 kStageTxtPos = D3DXVECTOR2(1000.0f, 775.0f);
	const int kStagePicWidth	= 850;
	const int kStagePicHeight	= 550;
	const int kStageTxtWidth	= 850;
	const int kStageTxtHeight	= 150;
};
#endif