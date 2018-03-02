#ifndef RENDERER_H
#define RENDERER_H

#include"Utility.h"

using Utility::CUSTOMVERTEX;

class Renderer {
public:
	static void CreateInstance();
	static Renderer& GetInstance();

	//絶対座標変換します
	//第一引数 描画したい座標
	//第二引数 Y軸での回転(度数）（デフォルトは0）
	//第三引数 X軸での回転（度数）（デフォルトは0）
	//第四引数 Z軸での回転（度数）（デフォルトは0）
	//第五引数 拡縮率（デフォルトは1.0）
	void TransformWorld(const D3DXVECTOR3& pos, float degHeading = 0.0f, float degPitch = 0.0f, float degBank = 0.0f, float scale = 1.0f);

	//視点座標変換します
	//第一引数 カメラ座標
	//第三引数 Y軸でのカメラの回転（度数）
	//第四引数 Z軸でのカメラの回転（度数）
	void TransformView(const D3DXVECTOR3& cameraPos, const D3DXVECTOR3& lookatPos, const D3DXVECTOR3& upVec);

	D3DXVECTOR3* GetLookatPos(D3DXVECTOR3* pPos, float length, float degHeading, float degBank);

	//射影変換します
	//第一引数 視野角（度数）（デフォルトは45度）
	//第二引数 アスペクト比（デフォルトは1.0）
	//第三引数 可視できる最小距離（デフォルトは1.0）
	//第四引数 可視できる最大距離（デフォルトは100.0）
	void TransformProjection(float angle = 45.0f, float aspectRatio = 1.0f, float mimDistance = 1.0f, float maxDistance = 100.0f);

	//3D描画を始める準備
	void StartRender();

	//2D描画を始める準備
	void StartDraw(int red, int green, int blue);

	bool Draw(const D3DXVECTOR2& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const D3DXVECTOR3& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const CUSTOMVERTEX vertex[], const char* fileName);

	//描画関数
	//第一引数 そのメッシュのID
	bool Render(const char* fileName);

	//描画終了
	void EndRender();
	void EndDraw();

	void TurnVertex_tu(CUSTOMVERTEX vertex[]);
	void TurnVertex_tv(CUSTOMVERTEX vertex[]);
	void ChangeScale(CUSTOMVERTEX vertex[], float magnifying);
	void TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight);
	void Rotation(CUSTOMVERTEX vertex[], float deg);

	LPDIRECT3DDEVICE9* GetDXDevice() { return m_pDXDevice; }

private:
	static Renderer* pInstance;
	Renderer();
	~Renderer();

	LPDIRECT3DDEVICE9* m_pDXDevice;

	Renderer(const Renderer&);
	void operator =(const Renderer&);
};
#endif