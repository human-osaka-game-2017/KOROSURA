#ifndef EFFECT_H
#define EFFECT_H

#include "Shader.h"
#include "DirectGraphics.h"

class Effect {
public:
	//Fxファイルの読み込み
	Effect(std::string FxPath);
	~Effect();
	//Shaderの開始
	void BeginPass();
	//Shaderの終わり
	void EndPass();
private:
	void LoadingFx(std::string fxfilePath);
	LPD3DXEFFECT m_Effect;
};

#endif