/**
 * @file	Fonts.h
 * @brief	namespace Fontsのヘッダ
 * @author	shiraishi
 */
#ifndef FONTS_H
#define FONTS_H

#include"Utility.h"

/**
 * @namespace	Fonts
 * @brief		namespace Fonts
 * @details		UV値を入れて返す関数とfonts画像の幅高さのグローバル変数
 */
namespace Fonts {

	/**
	 * @brief		フォントのUVを返してくれる関数
	 * @param[in]	ch		返してほしい文字
	 * @param[out]	vertex	UV値を入れてくれる箱
	 * @return		Utility::CUSTOMVERTEX*	第二引数
	 */
	Utility::CUSTOMVERTEX* GetUV(const char ch, Utility::CUSTOMVERTEX* vertex);

	extern const int g_Width;	//56
	extern const int g_Height;	//98
	extern const int g_PngSize;	//1024
}
#endif