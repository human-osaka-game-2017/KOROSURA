#ifndef BILLBOARD_H
#define BILLBOARD_H

#include"Lib.h"
#include"DirectGraphics.h"

class Billboard
{
public:
	static Billboard& GetInstans();
	void BillboardingTransform(D3DXVECTOR3 pos,float scale);
private:
	static Billboard* pInstance;
	Billboard() {};
	~Billboard() { delete pInstance; };
};

#endif
