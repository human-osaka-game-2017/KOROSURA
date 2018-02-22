/**
 * @file	Shader.h
 * @brief	シェーダーを使った描画
 * @author	北川　翔馬
 */
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>
#include <d3dx9.h>

class Effect;
//Effectクラスを管理するクラス
class FxManager {
public:
	static void CreateInstance();
	static FxManager& GetpInstance() {return *pInstance;}
	//Effectクラスを返す
	Effect* GetFxEffect(std::string EffectPath) { return m_FxEffect[EffectPath]; }
	//Effectの解放処理
	void ReleaseEffect(std::string EffectPath);
	//Effectの生成
	void CreateEffect(std::string EffectPath);
	
private:
	FxManager() {};
	~FxManager() {};
	static FxManager* pInstance;
	//Effectクラスを持つ
	std::map<std::string,Effect*> m_FxEffect;
};
#endif