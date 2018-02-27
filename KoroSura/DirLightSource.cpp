#include "DirLightSource.h"

DirLightSource* DirLightSource::pInstance = nullptr;

void DirLightSource::CreateInstance()
{
	if (pInstance == nullptr) {
		pInstance = new DirLightSource();
	}
}

DirLightSource::DirLightSource()
{
	m_LightDir = D3DXVECTOR4(1, 0, 0, 0);
}

void DirLightSource::Update()
{
	m_LightDir.x += 1.f;
	m_LightDir.z += 1.f;
}