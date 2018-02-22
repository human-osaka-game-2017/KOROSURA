#ifndef EFFECT_H
#define EFFECT_H

#include "Shader.h"
#include "DirectGraphics.h"

class Effect {
public:
	//Fx�t�@�C���̓ǂݍ���
	Effect(std::string FxPath);
	~Effect() {};
	//Shader�̊J�n
	void BeginPass();
	//Shader�̏I���
	void EndPass();
	LPD3DXEFFECT GetEffect() { return m_Effect; }
private:
	void LoadingFx(std::string fxfilePath);
	LPD3DXEFFECT m_Effect;
};

#endif