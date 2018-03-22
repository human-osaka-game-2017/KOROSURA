#include"Billboard.h"
#include"Camera.h"
#include"Lib.h"
#include"DirectGraphics.h"
#include"Camera.h"
#include"CameraIvent.h"

Billboard* Billboard::pInstance = nullptr;

Billboard& Billboard::GetInstans() {
	if (pInstance == nullptr) {
		pInstance = new Billboard();
	}
	return *pInstance;
}

void Billboard::BillboardingTransform(D3DXVECTOR3 pos, float scale)
{
	//最終的なワールドトランスフォーム行列
	D3DXMATRIXA16 matWorld;
	//平行移動用行列
	D3DXMATRIXA16 matPosition;
	//拡縮用行列
	D3DXMATRIXA16 matScale;

	//行列の初期化
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matPosition);
	D3DXMatrixIdentity(&matScale);

	//ワールドトランスフォーム（絶対座標変換）
	//拡縮
	D3DXMatrixScaling(&matScale, scale, scale, scale);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matScale);

	D3DXMATRIX ViewMatrix;
	
	CreateBillBoardMatrix(&pos, &CameraIvent::GetInstance().GetCameraPos(), &ViewMatrix);
	D3DXMatrixMultiply(&matWorld, &matWorld, &ViewMatrix);
	//平行移動
	D3DXMatrixTranslation(&matPosition, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

	//レンダリング仕様の登録
	(*DirectGraphics::GetInstance().GetDevice())->SetTransform(D3DTS_WORLD, &matWorld);
}


void Billboard::CreateBillBoardMatrix(D3DXVECTOR3* _pEnemyUIPos, D3DXVECTOR3* _pCameraPos, D3DXMATRIX* _pOutMatrix)
{
	D3DXMatrixIdentity(_pOutMatrix);
	D3DXMatrixLookAtLH(_pOutMatrix, _pCameraPos, _pEnemyUIPos, &D3DXVECTOR3(0, 1, 0));
	D3DXMatrixInverse(_pOutMatrix, NULL, _pOutMatrix);
	_pOutMatrix->_41 = 0.0f;
	_pOutMatrix->_42 = 0.0f;
	_pOutMatrix->_43 = 0.0f;
}