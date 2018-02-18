#include "Shader.h"
#include "DirectGraphics.h"

FxManager* FxManager::pInstance = nullptr;

void FxManager::CreateInstance()
{
	if (pInstance != nullptr) {
		pInstance = new FxManager();
	}
}

void FxManager::CreateEffect(std::string EffectPath)
{
	m_FxEffect[EffectPath] = new Effect(EffectPath);
}

void FxManager::ReleaseEffect(std::string EffectPath)
{
	delete m_FxEffect[EffectPath];
}