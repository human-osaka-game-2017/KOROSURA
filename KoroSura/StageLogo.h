/**
 * @file	StageLogo.h
 * @brief	StageLogoクラスのヘッダ
 * @author	shiraishi
 */
#ifndef STAGELOGO_H
#define STAGELOGO_H

#include"StageSelectBase.h"
#include"Utility.h"

class Enlarger;

 /**
  * @brief		各ステージ番号を表示するクラス
  * @details	選択されているステージ番号を拡大、スライムカーソルを表示
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

	//Stage1の'S'の中心座標
	const D3DXVECTOR2 m_Pos;

	const int kFontWidth	= 33;
	const int kFontHeight	= 98;
	//const int kFrameWidth	= 200;
	//const int kFrameHeight	= 100;
	const int kFrameWidth = 350;
	const int kFrameHeight = 100;
};
#endif