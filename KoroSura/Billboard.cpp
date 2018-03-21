#include"Billboard.h"
#include"Camera.h"
#include"Lib.h"
#include"DirectGraphics.h"

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
	//現在のビュー行列を得る
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	//もらったビューの行列変換をおこなう
	D3DXMatrixInverse(&ViewMatrix, NULL, &ViewMatrix);


	D3DXMatrixMultiply(&matWorld, &matWorld, &ViewMatrix);
	//平行移動
	D3DXMatrixTranslation(&matPosition, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

	//レンダリング仕様の登録
	(*DirectGraphics::GetInstance().GetDevice())->SetTransform(D3DTS_WORLD, &matWorld);
}

