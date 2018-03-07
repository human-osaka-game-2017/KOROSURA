/**
 * @file	Shader.h
 * @brief	�V�F�[�_�[���g�����`��
 * @author	�k��@�Ĕn
 */
#ifndef SHADER_H
#define SHADER_H

#include<string>
#include<map>
#include<d3dx9.h>
#include"Effect.h"

//Effect�N���X���Ǘ�����N���X
class EffectManager {
public:
	static EffectManager& GetpInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new EffectManager;
		}return *m_pInstance;
	}

	//Effect�N���X��Ԃ�
	Effect* GetEffect(std::string EffectPath) { return m_PtrEffects[EffectPath]; }

	//Effect�̐���
	void CreateEffect(std::string EffectPath);

	//Effect�̉������
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