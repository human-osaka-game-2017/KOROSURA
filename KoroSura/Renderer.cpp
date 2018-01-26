#include"Renderer.h"
#include"DirectGraphics.h"
#include"ModelManager.h"
#include"TextureManager.h"

Renderer* Renderer::pInstance = nullptr;

void Renderer::CreateInstance() {
	if (pInstance == nullptr) {
		pInstance = new Renderer();
	}
}

Renderer& Renderer::GetInstance() {
	if (pInstance == nullptr) {
		MessageBox(0, "Rendererインスタンスが生成されていません", "", MB_OK);
	}
	return *pInstance;
}

Renderer::Renderer() {
	m_pDXDevice = DirectGraphics::GetInstance().GetDevice();
}

Renderer::~Renderer() {
	delete pInstance;
}

void Renderer::TransformWorld(const D3DXVECTOR3& pos, float degHeading, float degPitch, float degBank, float scale) {
	//最終的なワールドトランスフォーム行列
	D3DXMATRIXA16 matWorld;
	//平行移動用行列
	D3DXMATRIXA16 matPosition;
	//回転用行列
	D3DXMATRIXA16 matRotation;
	//拡縮用行列
	D3DXMATRIXA16 matScale;

	float radX, radY, radZ;
	radX = D3DXToRadian(degPitch);
	radY = D3DXToRadian(degHeading);
	radZ = D3DXToRadian(degBank);

	//行列の初期化
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matRotation);
	D3DXMatrixIdentity(&matRotation);

	//ワールドトランスフォーム（絶対座標変換）
	//拡縮
	D3DXMatrixScaling(&matScale, scale, scale, scale);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matScale);

	//回転
	D3DXMatrixRotationX(&matRotation, radX);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);
	D3DXMatrixRotationY(&matRotation, radY);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);
	D3DXMatrixRotationZ(&matRotation, radZ);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);

	//平行移動
	D3DXMatrixTranslation(&matPosition, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

	//レンダリング仕様の登録
	(*m_pDXDevice)->SetTransform(D3DTS_WORLD, &matWorld);
}

void Renderer::TransformView(const D3DXVECTOR3& cameraPos, const D3DXVECTOR3&  lookatPos, const D3DXVECTOR3& upVec) {
	//最終的なビュートランスフォーム行列
	D3DXMATRIXA16 matView;

	// ビュートランスフォーム（視点座標変換）
	D3DXMATRIXA16 matCameraPosition;
	D3DXVECTOR3 vecEyePt = cameraPos; //カメラ（視点）位置
	D3DXVECTOR3 vecLookatPt = lookatPos;//注視位置
	D3DXVECTOR3 vecUpVec = upVec;//上方位置      
	D3DXMatrixIdentity(&matView);
	D3DXMatrixLookAtLH(&matCameraPosition, &vecEyePt, &vecLookatPt, &vecUpVec);
	D3DXMatrixMultiply(&matView, &matView, &matCameraPosition);

	//レンダリング仕様の登録
	(*m_pDXDevice)->SetTransform(D3DTS_VIEW, &matView);
}

D3DXVECTOR3* Renderer::GetLookatPos(D3DXVECTOR3* pPos, float length, float degHeading, float degBank) {
	float radHeading, radBank;
	radHeading = D3DXToRadian(degHeading);
	radBank = D3DXToRadian(degBank);

	pPos->x += length*(float)cos(radBank)*(float)cos(radHeading);
	pPos->y += length*(float)sin(radBank);
	pPos->z += length*(float)cos(radBank)*(float)sin(radHeading);

	return pPos;
}

void Renderer::TransformProjection(float angle, float aspectRatio, float mimDistance, float maxDistance) {
	// プロジェクショントランスフォーム（射影変換）
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, angle, aspectRatio, mimDistance, maxDistance);

	//レンダリング仕様の登録
	(*m_pDXDevice)->SetTransform(D3DTS_PROJECTION, &matProj);
}

void Renderer::StartRender() {
	// レンダリング
	(*m_pDXDevice)->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);

	(*m_pDXDevice)->BeginScene();
}

void Renderer::StartDraw(int red, int green, int blue) {
	(*m_pDXDevice)->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(red, green, blue),
		1.0, 0);

	(*m_pDXDevice)->BeginScene();
}

bool Renderer::Render(const char* fileName) {
	ModelManager::ModelData model = ModelManager::GetInstance().GetModelData(fileName);

	for (DWORD i = 0; i < model.DwNumMaterials; i++)
	{
		(*m_pDXDevice)->SetMaterial(&model.pMeshMaterials[i]);
		(*m_pDXDevice)->SetTexture(0, model.pMeshTextures[i]);
		model.pMesh->DrawSubset(i);
	}
	return true;
}

bool Renderer::Draw(const D3DXVECTOR3& pos, const char* fileName, float width, float height, float tu, float tv, float deg, float magnifying, DWORD color, bool flipHorizontal, bool flipVertical) {
	D3DXVECTOR2 pos2;
	pos2.x = pos.x;
	pos2.y = pos.y;
	if (Draw(pos2, fileName, width, height, tu, tv, deg, magnifying, color, flipHorizontal, flipVertical)) {
		return true;
	}
	return false;
}

bool Renderer::Draw(const D3DXVECTOR2& pos, const char* fileName, float width, float height, float tu, float tv, float deg, float magnifying, DWORD color, bool flipHorizontal, bool flipVertical) {
	Utility::PICTURE_INFO pic = TextureManager::GetInstance().GetPictureInfo(fileName);

	CUSTOMVERTEX vertex[]{
		{ -width / 2,-height / 2,0.5f,1.0f,color,0.0f,0.0f },
		{ width / 2,-height / 2,0.5f,1.0f,color,1.0f,0.0f },
		{ width / 2, height / 2,0.5f,1.0f,color,1.0f,1.0f },
		{ -width / 2, height / 2,0.5f,1.0f,color,0.0f,1.0f }
	};

	CUSTOMVERTEX drawVertex[4];
	for (int i = 0; i < 4; i++) {
		drawVertex[i] = vertex[i];
		drawVertex[i].x += pos.x;
		drawVertex[i].y += pos.y;
	}

	TrimingVertex(drawVertex, tu, tv, width, height, (float)pic.width, (float)pic.height);

	ChangeScale(drawVertex, magnifying);

	Rotation(drawVertex, deg);

	if (flipHorizontal) {
		TurnVertex_tu(drawVertex);
	}
	if (flipVertical) {
		TurnVertex_tv(drawVertex);
	}

	return Draw(drawVertex, fileName);
}

bool Renderer::Draw(const CUSTOMVERTEX vertex[], const char* fileName) {
	Utility::PICTURE_INFO pic = TextureManager::GetInstance().GetPictureInfo(fileName);

	// テクスチャをステージに割り当てる
	if (FAILED((*m_pDXDevice)->SetTexture(0, pic.texture)))
	{
		return false;
	}
	// 描画
	if (FAILED((*m_pDXDevice)->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX))))
	{
		return false;
	}

	return true;
}

void Renderer::EndRender() {
	(*m_pDXDevice)->EndScene();
	(*m_pDXDevice)->Present(NULL, NULL, NULL, NULL);
}

void Renderer::EndDraw() {
	(*m_pDXDevice)->EndScene();
	(*m_pDXDevice)->Present(NULL, NULL, NULL, NULL);
}

void Renderer::TurnVertex_tu(CUSTOMVERTEX vertex[]) {
	CUSTOMVERTEX tmpVertex;

	tmpVertex.tu = vertex[0].tu;
	vertex[0].tu = vertex[1].tu;
	vertex[1].tu = tmpVertex.tu;

	tmpVertex.tu = vertex[3].tu;
	vertex[3].tu = vertex[2].tu;
	vertex[2].tu = tmpVertex.tu;

}

void Renderer::TurnVertex_tv(CUSTOMVERTEX vertex[]) {
	CUSTOMVERTEX tmpVertex;

	tmpVertex.tv = vertex[0].tv;
	vertex[0].tv = vertex[3].tv;
	vertex[3].tv = tmpVertex.tv;

	tmpVertex.tv = vertex[1].tv;
	vertex[1].tv = vertex[2].tv;
	vertex[2].tv = tmpVertex.tv;

}

void Renderer::ChangeScale(CUSTOMVERTEX vertex[], float magnifying) {
	float halfWidth = (vertex[1].x - vertex[0].x) / 2;
	float halfHeight = (vertex[0].y - vertex[3].y) / 2;

	float centerX, centerY;
	centerX = vertex[0].x + halfWidth;
	centerY = vertex[0].y - halfHeight;

	vertex[0].x = centerX + -halfWidth*magnifying;
	vertex[0].y = centerY + halfHeight*magnifying;
	vertex[1].x = centerX + halfWidth*magnifying;
	vertex[1].y = centerY + halfHeight*magnifying;
	vertex[2].x = centerX + halfWidth*magnifying;
	vertex[2].y = centerY + -halfHeight*magnifying;
	vertex[3].x = centerX + -halfWidth*magnifying;
	vertex[3].y = centerY + -halfHeight*magnifying;
}

void Renderer::TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight) {
	vertex[0].tu = leftTopTu / pngWidth;
	vertex[0].tv = leftTopTv / pngHeight;

	vertex[1].tu = (leftTopTu + width) / pngWidth;
	vertex[1].tv = leftTopTv / pngHeight;

	vertex[2].tu = (leftTopTu + width) / pngWidth;
	vertex[2].tv = (leftTopTv + height) / pngHeight;

	vertex[3].tu = leftTopTu / pngWidth;
	vertex[3].tv = (leftTopTv + height) / pngHeight;

}

void Renderer::Rotation(CUSTOMVERTEX vertex[], float deg) {
	float cx, cy;
	float rad;
	CUSTOMVERTEX tmpVertex[4];

	rad = D3DXToRadian(deg);

	cx = (vertex[0].x + vertex[1].x) / 2.0f;
	cy = (vertex[0].y + vertex[3].y) / 2.0f;

	for (int i = 0; i < 4; i++) {
		vertex[i].x -= cx;
		vertex[i].y -= cy;

		tmpVertex[i] = vertex[i];
		vertex[i].x = tmpVertex[i].x * cos(rad)
			- tmpVertex[i].y * sin(rad);
		vertex[i].y = tmpVertex[i].x * sin(rad)
			+ tmpVertex[i].y * cos(rad);
		vertex[i].x += cx;
		vertex[i].y += cy;
	}
}