#ifndef LIB_H
#define LIB_H

#include<Windows.h>
#include<string>
#include"Utility.h"

class DirectGraphics;
class DirectInput;
class SoundBufferManager;
class Renderer;
class ModelManager;
class TextureManager;

class Lib {
public:
	static void CreateInstance(HWND hWnd, HINSTANCE hInstance);
	static Lib& GetInstance();

	void UpdateKey();

	void UpdateMouse();

	/*!
	* キーボードの状態を取得
	* @param keyKind キーボード識別ID
	* @return キーボードのボタンの状態
	*/
	Utility::BUTTON_STATE GetKeyState(Utility::KEY_KIND keyKind);

	/*!
	* マウスの状態を取得
	* @return マウスの状態
	*/
	const Utility::MouseData* GetMouseData();

	/*!
	* 登録されているモデルデータの削除
	* @param fileName 
	*/
	void CancelModel(const char* fileName);

	/*!
	* Xファイルからデータを登録
	* @param fileName
	*/
	HRESULT LoadXFile(const char* fileName);

	/*!
	* 
	* @param fileName
	*/
	//絶対座標変換します
	//第一引数 描画したい座標
	//第二引数 Y軸での回転(度数）（デフォルトは0）
	//第三引数 X軸での回転（度数）（デフォルトは0）
	//第四引数 Z軸での回転（度数）（デフォルトは0）
	//第五引数 拡縮率（デフォルトは1.0）
	void TransformWorld(const D3DXVECTOR3& pPos, float degHeading = 0.0f, float degPitch = 0.0f, float degBank = 0.0f, float scale = 1.0f);

	//視点座標変換します
	//第一引数 カメラ座標
	//第三引数 Y軸でのカメラの回転（度数）
	//第四引数 Z軸でのカメラの回転（度数）
	void TransformView(const D3DXVECTOR3& pCameraPos, const D3DXVECTOR3&  LookatPos, const D3DXVECTOR3& UpVec);

	D3DXVECTOR3* GetLookatPos(D3DXVECTOR3* pos, float length, float degHeading, float degBank);

	//射影変換します
	//第一引数 視野角（度数）（デフォルトは45度）
	//第二引数 アスペクト比（デフォルトは1.0）
	//第三引数 可視できる最小距離（デフォルトは1.0）
	//第四引数 可視できる最大距離（デフォルトは100.0）
	void TransformProjection(float angle = 45.0f, float aspectRatio = 1.0f, float mimDistance = 1.0f, float maxDistance = 100.0f);

	void SetRenderState2D();

	void SetRenderState3D();

	/*!
	* 3Dを描画する前に必ず呼ぶこと
	*/
	void StartRender();

	/*!
	* 2Dを描画する前に必ず呼ぶこと
	*/
	void StartDraw(int red = 0xff, int green = 0xff, int blue = 0xff);

	bool Draw(const D3DXVECTOR3& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const D3DXVECTOR2& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const Utility::CUSTOMVERTEX vertex[], const char* fileName);

	//描画関数
	//第一引数 そのメッシュのID
	bool Render(const char* fileName);

	//描画終了
	void EndRender();
	void EndDraw();

	void TurnVertex_tu(Utility::CUSTOMVERTEX vertex[]);
	void TurnVertex_tv(Utility::CUSTOMVERTEX vertex[]);
	void ChangeScale(Utility::CUSTOMVERTEX vertex[], float magnifying);
	void TrimingVertex(Utility::CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight);
	void Rotation(Utility::CUSTOMVERTEX vertex[], float deg);

	//テキスチャを消します
	void CancelTexture(const char* fileName);

	//png,jpegファイルからデータを読み込みます
	//第一引数 ファイルへのパス
	//第二引数 そのテキスチャのID
	HRESULT LoadPictureFile(const char* fileName, int width, int height, bool canSemitransparent = true);

	bool LoadWaveFile(const char* fileName);

	void CancelSound(std::string fileName);

	void PlayBackSound(std::string fileName, bool isLoop);

	void StopSound(std::string fileName);

private:
	static Lib* pInstance;
	Lib(HWND hWnd, HINSTANCE hInstance);
	~Lib();

	DirectGraphics* m_pDirectGraphics;
	DirectInput* m_pDirectInput;
	Renderer* m_pRenderer;
	ModelManager* m_pModelManager;
	TextureManager* m_pTextureManager;
	SoundBufferManager* m_pSoundBufferManager;

	Lib(const Lib&);
	void operator =(const Lib&);
};
#endif
