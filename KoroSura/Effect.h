#ifndef EFFECT_H
#define EFFECT_H

#include<d3dx9.h>
#include<string>

#include"FBX.h"

class Effect {
public:
	//Fxファイルの読み込み
	Effect(std::string FxPath);
	~Effect() {};

	//Shaderの開始
	void BeginPass(int technique);

	//Shaderの終わり
	void EndPass();

	void SetWorldMatrix(D3DXMATRIX* matrix);
	void SetViewMatrix(D3DXMATRIX* matrix);
	void SetProjMatrix(D3DXMATRIX* matrix);
	void Effect::SetColor(FBXLoader::Color_RGB Color, float alpha);
	void SetLightVector();

private:
	void LoadFxFile(std::string fxfilePath);
	LPD3DXEFFECT m_Effect;

	D3DXHANDLE m_World;
	D3DXHANDLE m_Technique;	//!< テクニックハンドル.
	D3DXHANDLE m_View;
	D3DXHANDLE m_Proj;
	D3DXHANDLE m_Light;
	D3DXHANDLE m_Color;
};
#endif