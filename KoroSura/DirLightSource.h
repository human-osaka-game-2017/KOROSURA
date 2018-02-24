#ifndef DIRLIGHTSOURCE_H
#define DIRLIGHTSOURCE_H

#include "Shader.h"
#include "Effect.h"

class DirLightSource {
public:
	static void CreateInstance();
	static DirLightSource& GetpInstance() { return *pInstance; }
	D3DXVECTOR4 GetlightDir() {return m_LightDir;}
	void Update();
private:
	static DirLightSource* pInstance;

	DirLightSource();
	~DirLightSource() {};
	D3DXVECTOR4 m_LightDir;
};

#endif 
