/**
 * @file	Sky.h
 * @brief	Skyクラスのヘッダ
 * @author	shiraishi
 */

#ifndef SKY_H
#define SKY_H

#include"MaterialBase.h"

class Sky :public MaterialBase {
public:
	Sky():
		MaterialBase(D3DXVECTOR3(0.0f,0.0f,0.0f), D3DXVECTOR3(0.0f,1.0f,0.0f))
	{};
	virtual ~Sky() {};

	virtual void Update();
	virtual void DrawPreparation();
	virtual void Draw();
};
#endif