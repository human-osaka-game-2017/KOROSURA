#include"DirectGraphics.h"

DirectGraphics* DirectGraphics::pInstance = nullptr;

void DirectGraphics::CreateInstance(HWND hWnd) {
	if (pInstance == nullptr) {
		pInstance = new DirectGraphics(hWnd);
	}
}

DirectGraphics& DirectGraphics::GetInstance() {
	if (pInstance == nullptr) {
		MessageBox(0, "DirectInputインスタンスが生成されていません", "", MB_OK);
	}
	return *pInstance;
}

DirectGraphics::DirectGraphics(HWND hWnd) {

	m_HWnd = hWnd;

	// 「Direct3D」オブジェクトの作成
	if (NULL == (m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3Dの作成に失敗しました", "", MB_OK);
	}

	//Display Mode の設定
	D3DDISPLAYMODE D3DdisplayMode;
	m_pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&D3DdisplayMode);

	// 「DIRECT3Dデバイス」オブジェクトの作成
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	d3dpp.BackBufferFormat = D3DdisplayMode.Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	if (FAILED(m_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp, &m_pDevice)))
	{
		MessageBox(0, "HALモードでDIRECT3Dデバイスを作成できません\nREFモードで再試行します", NULL, MB_OK);
		if (FAILED(m_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&d3dpp, &m_pDevice)))
		{
			MessageBox(0, "DIRECT3Dデバイスの作成に失敗しました", NULL, MB_OK);
		}
	}

	m_pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	//viewport設定
	D3DVIEWPORT9 Viewport{ 0,0,d3dpp.BackBufferWidth,d3dpp.BackBufferHeight,0.0f,1.0f };
	m_pDevice->SetViewport(&Viewport);
}

DirectGraphics::~DirectGraphics() {
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pDirect3D);

	delete pInstance;
}

HWND DirectGraphics::GethWnd() {
	return m_HWnd;
}

void DirectGraphics::SetRenderState3D(){
	m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);
	// Zバッファー処理を有効にする
	m_pDevice->SetRenderState(D3DRS_ZENABLE, true);
	// ライトを有効にする
	m_pDevice->SetRenderState(D3DRS_LIGHTING, true);
	// アンビエントライト（環境光）を設定する
	m_pDevice->SetRenderState(D3DRS_AMBIENT, 0x00111111);
	// スペキュラ（鏡面反射）を有効にする
	m_pDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	// ライトをあてる 白色ライト、鏡面反射有りに設定
	D3DXVECTOR3 vecDirection(1, 1, 1);
	D3DLIGHT9 d3dLight;
	ZeroMemory(&d3dLight, sizeof(D3DLIGHT9));
	d3dLight.Type = D3DLIGHT_DIRECTIONAL;
	d3dLight.Diffuse.r = 1.0f;
	d3dLight.Diffuse.g = 1.0f;
	d3dLight.Diffuse.b = 1.0f;
	d3dLight.Specular.r = 1.0f;
	d3dLight.Specular.g = 1.0f;
	d3dLight.Specular.b = 1.0f;
	D3DXVec3Normalize((D3DXVECTOR3*)&d3dLight.Direction, &vecDirection);
	d3dLight.Range = 200.0f;
	m_pDevice->SetLight(0, &d3dLight);
	m_pDevice->LightEnable(0, TRUE);
}

void DirectGraphics::SetRenderState2D() {
	m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);
	m_pDevice->SetRenderState(D3DRS_ZENABLE, false);

	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}