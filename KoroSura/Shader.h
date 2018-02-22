/**
 * @file	Shader.h
 * @brief	�V�F�[�_�[���g�����`��
 * @author	�k��@�Ĕn
 */
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>
#include <d3dx9.h>

class Effect;
//Effect�N���X���Ǘ�����N���X
class FxManager {
public:
	static void CreateInstance();
	static FxManager& GetpInstance() {return *pInstance;}
	//Effect�N���X��Ԃ�
	Effect* GetFxEffect(std::string EffectPath) { return m_FxEffect[EffectPath]; }
	//Effect�̉������
	void ReleaseEffect(std::string EffectPath);
	//Effect�̐���
	void CreateEffect(std::string EffectPath);
	
private:
	FxManager() {};
	~FxManager() {};
	static FxManager* pInstance;
	//Effect�N���X������
	std::map<std::string,Effect*> m_FxEffect;
};
#endif