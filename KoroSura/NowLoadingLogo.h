/**
 * @file	NowLoadingLogo.h
 * @brief	NowLoadingクラスのヘッダ
 * @author	shiraishi
 */
#ifndef NOWLOADINGLOGO_H
#define NOWLOADINGLOGO_H
#include<d3dx9.h>


class NowLoadingLogo{
public:
	NowLoadingLogo();
	~NowLoadingLogo();

	void Draw();

private:
	const int kPngWidth = 8192;
	const int kPngHeight = 1024;

	D3DXVECTOR2 kSlimePos = D3DXVECTOR2(800.0f, 500.0f);

	const int kSlimeWidth = 150;
	const int kSlimeHeight = 150;

	const float kRotasionSpeed = 2.0f;
	float m_Deg = 0.0f;
};

#endif