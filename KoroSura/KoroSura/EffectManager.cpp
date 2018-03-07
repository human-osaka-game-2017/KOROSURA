#include "EffectManager.h"

EffectManager* EffectManager::m_pInstance = nullptr;

void EffectManager::CreateEffect(std::string EffectPath)
{
	m_PtrEffects[EffectPath] = new Effect(EffectPath);
}

void EffectManager::ReleaseEffect(std::string EffectPath)
{
	delete m_PtrEffects[EffectPath];
}