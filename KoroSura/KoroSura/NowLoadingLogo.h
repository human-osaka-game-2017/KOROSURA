/**
 * @file	NowLoadingLogo.h
 * @brief	NowLoadingクラスのヘッダ
 * @author	shiraishi
 */
#ifndef NOWLOADINGLOGO_H
#define NOWLOADINGLOGO_H

class NowLoadingLogo{
public:
	NowLoadingLogo();
	~NowLoadingLogo();

	void Draw();

private:
	const float kRotasionSpeed = 2.0f;
	float m_Deg = 0.0f;
};
#endif