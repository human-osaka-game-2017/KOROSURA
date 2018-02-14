#include"Lib.h"
#include"Common.h"
#include"SceneManager.h"
#include "FBXModel.h"
#include "DirectGraphics.h"
#include "Renderer.h"
#include "ModelManager.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_KEYDOWN:        // キーが押されたとき
		if (wp == VK_ESCAPE)
		{
			DestroyWindow(hWnd);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow) {
	HWND hWnd;

	WNDCLASSEX Wndclass;
	Wndclass.cbSize = sizeof(WNDCLASSEX);
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = NULL;
	Wndclass.hCursor = NULL;
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TEXT("WINDOW");
	Wndclass.hIconSm = NULL;

	//Windowの登録
	RegisterClassEx(&Wndclass);

	//Windowの生成
	hWnd = CreateWindow(
		TEXT("WINDOW"),								//ウィンドウのクラス名
		"KOROSURA", 							//ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,			//ウィンドウスタイル
		CW_USEDEFAULT,								// ウィンドウの横方向の位置x
		CW_USEDEFAULT,								// ウィンドウの縦方向の位置y
		WINDOW_WIDTH,								// Width（幅）
		WINDOW_HEIGHT,								// Height（高さ）
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
	);
	SetProcessDPIAware();

	//resize
	RECT rextWindow, rectClient;
	GetWindowRect(hWnd, &rextWindow);
	GetClientRect(hWnd, &rectClient);

	int newWidth = (rextWindow.right - rextWindow.left) - (rectClient.right - rectClient.left) + WINDOW_WIDTH;
	int newHeight = (rextWindow.bottom - rextWindow.top) - (rectClient.bottom - rectClient.top) + WINDOW_HEIGHT;

	SetWindowPos(hWnd, NULL, 0, 0, newWidth, newHeight, SWP_NOMOVE | SWP_NOZORDER);
	ShowWindow(hWnd, SW_SHOW);
	ShowCursor(false);

	Lib::CreateInstance(hWnd, hInstance);
	FBXLoader::CreateFBXInstance();

	SceneManager game;

	ModelManager::GetInstance().LoadFBXFile("FBXModel/house_red.fbx");

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	DWORD prevTime = timeGetTime();
	DWORD currentTime;

	timeBeginPeriod(1);
	int frCnt = 0;

	float tmp = 0;

	while (msg.message != WM_QUIT) {

		currentTime = timeGetTime();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != false) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			if (currentTime - prevTime >= 1000 / 60) {
				++frCnt;
				Lib::GetInstance().UpdateKey();
				//ワールドトランスフォーム（絶対座標変換）
				Lib::GetInstance().TransformWorld(D3DXVECTOR3(0, 0, 0));
				Lib::GetInstance().TransformView(D3DXVECTOR3(0, 500, 1000), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 1, 0));
				Lib::GetInstance().TransformProjection(45.0f, WINDOW_WIDTH / WINDOW_HEIGHT,1.0f,5000.0f);

				// ライトをあてる 白色で鏡面反射ありに設定
				D3DXVECTOR3 vecDirection(0, 0, 1);
				D3DLIGHT9 light;
				ZeroMemory(&light, sizeof(D3DLIGHT9));
				light.Type = D3DLIGHT_DIRECTIONAL;
				light.Diffuse.r = 1.0f;
				light.Diffuse.g = 1.0f;
				light.Diffuse.b = 1.0f;
				light.Attenuation0 = 0.f;
				light.Attenuation1 = 1.f;
				light.Attenuation2 = 0.f;
				light.Position.x = 0.f;
				light.Position.y = 100.f;
				light.Position.z = 1000.f;
				D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, &vecDirection);
				light.Range = 5000.0f;
				(*DirectGraphics::GetInstance().GetDevice())->SetLight(0, &light);
				(*DirectGraphics::GetInstance().GetDevice())->LightEnable(0, FALSE);
				(*DirectGraphics::GetInstance().GetDevice())->SetRenderState(D3DRS_LIGHTING, FALSE);
				(*DirectGraphics::GetInstance().GetDevice())->SetRenderState(D3DRS_AMBIENT, 0xff050505);
				Renderer::GetInstance().StartRender();
				ModelManager::GetInstance().Draw();
				Renderer::GetInstance().EndRender();
				//game.Run();
			}
		}

		if (currentTime - prevTime >= 1000) {
			//Utility::OutputDebug_Number((float)frCnt, hWnd);
			frCnt = 0;
			prevTime = currentTime;
		}
	}
	timeEndPeriod(1);

	return (int)msg.wParam;
}