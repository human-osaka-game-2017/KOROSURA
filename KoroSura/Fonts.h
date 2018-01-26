/**
 * @file	Fonts.h
 * @brief	namespace Fonts�̃w�b�_
 * @author	shiraishi
 */
#ifndef FONTS_H
#define FONTS_H

#include"Utility.h"

/**
 * @namespace	Fonts
 * @brief		namespace Fonts
 * @details		UV�l�����ĕԂ��֐���fonts�摜�̕������̃O���[�o���ϐ�
 */
namespace Fonts {

	/**
	 * @brief		�t�H���g��UV��Ԃ��Ă����֐�
	 * @param[in]	ch		�Ԃ��Ăق�������
	 * @param[out]	vertex	UV�l�����Ă���锠
	 * @return		Utility::CUSTOMVERTEX*	������
	 */
	Utility::CUSTOMVERTEX* GetUV(const char ch, Utility::CUSTOMVERTEX* vertex);

	extern const int g_Width;	//56
	extern const int g_Height;	//98
	extern const int g_PngSize;	//1024
}
#endif