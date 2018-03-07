/*!
* @file DirectInput.h
* @brief DirectInputクラス(シングルトン)のヘッダファイル
* @author shiraishi
*/

#ifndef DIRECTGRAPHICS_H
#define DIRECTGRAPHICS_H

#include<d3dx9.h>
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

class FileManagement;
class Renderer;

class DirectGraphics {
public:
	static void CreateInstance(HWND hWnd);
	static DirectGraphics& GetInstance();

	void SetRenderState2D();
	void SetRenderState3D();

	LPDIRECT3DDEVICE9* GetDevice() {
		return &m_pDevice;
	}

	HWND GethWnd();

private:
	static DirectGraphics* pInstance;
	DirectGraphics(HWND hWnd);
	~DirectGraphics();

	LPDIRECT3D9 m_pDirect3D = NULL;
	LPDIRECT3DDEVICE9 m_pDevice = NULL;
	HWND m_HWnd;

	DirectGraphics(const DirectGraphics&);
	void operator =(const DirectGraphics&);
};
#endif