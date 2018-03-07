/**
 * @file	Shader.h
 * @brief	シェーダーを使った描画
 * @author	北川　翔馬
 */
#ifndef SHADER_H
#define SHADER_H

#include<string>
#include<map>
#include<d3dx9.h>
#include"Effect.h"

//Effectクラスを管理するクラス
class EffectManager {
public:
	static EffectManager& GetpInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new EffectManager;
		}return *m_pInstance;
	}

	//Effectクラスを返す
	Effect* GetEffect(std::string EffectPath) { return m_PtrEffects[EffectPath]; }

	//Effectの生成
	void CreateEffect(std::string EffectPath);

	//Effectの解放処理
	void ReleaseEffect(std::string EffectPath);
	
private:
	EffectManager() {};
	~EffectManager() 
	{
		for (auto ite = m_PtrEffects.begin(); ite != m_PtrEffects.end(); ++ite) {
			delete (*ite).second;
		}
	};

	static EffectManager* m_pInstance;
	std::map<std::string,Effect*> m_PtrEffects;
};
#endif