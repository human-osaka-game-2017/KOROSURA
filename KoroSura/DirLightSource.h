#ifndef DIRLIGHTSOURCE_H
#define DIRLIGHTSOURCE_H

#include "Shader.h"
#include "Effect.h"

class DirLightSource {
public:
	DirLightSource();
	~DirLightSource();
	D3DXVECTOR4 GetlightDir() {return m_LightDir;}
private:
	D3DXVECTOR4 m_LightDir;
};

#endif 
