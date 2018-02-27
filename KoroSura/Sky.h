/**
 * @file	Sky.h
 * @brief	Skyクラスのヘッダ
 * @author	shiraishi
 */

#ifndef SLIME_H
#define SLIME_H

#include"MaterialBase.h"

class Sky :public MaterialBase {
public:
	Sky():
		MaterialBase(D3DXVECTOR3(0.0f,0.0f,0.0f), D3DXVECTOR3(0.0f,1.0f,0.0f))
	{};
	virtual ~Sky() {};

	virtual void Update() {};
	virtual void Draw();
};
#endif