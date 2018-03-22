#ifndef BILLBOARD_H
#define BILLBOARD_H

#include"Lib.h"
#include"DirectGraphics.h"

class Billboard
{
public:
	static Billboard& GetInstans();
	void BillboardingTransform(D3DXVECTOR3 pos,float scale);
	void CreateBillBoardMatrix(D3DXVECTOR3* _pEnemyUIPos, D3DXVECTOR3* _pCameraPos, D3DXMATRIX* _pOutMatrix);
private:
	static Billboard* pInstance;
	Billboard() {};
	~Billboard() { delete pInstance; };
};

#endif
