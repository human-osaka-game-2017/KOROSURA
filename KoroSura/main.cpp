#include"Lib.h"
#include"Common.h"
#include"SceneManager.h"
#include"FBXModel.h"
#include"DirectGraphics.h"
#include"Renderer.h"
#include"ModelManager.h"
#include"Shader.h"
#include"Effect.h"
#include"Terrain.h"
#include"Camera.h"
#include"Slime.h"
#include"DirLightSource.h"

//PlayerやEnemyごとに一つ持たせる
D3DXHANDLE		g_Technique;	//!< テクニックハンドル.


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
	FxManager::CreateInstance();
	DirLightSource::CreateInstance();

	Slime slime(D3DXVECTOR3(0, 0, 0));
	Camera camera(D3DXVECTOR3(300,300,300), D3DXVECTOR3 (0,0,0));


	SceneManager game;

	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\fence.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\sky.fbx");



	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	DWORD prevTime = timeGetTime();
	DWORD currentTime;

	timeBeginPeriod(1);
	int frCnt = 0;

	Terrain terrain;

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
				DirLightSource::GetpInstance().Update();
				slime.Update();
				camera.Update();
				Renderer::GetInstance().StartRender();
				slime.Draw();
				Renderer::GetInstance().EndRender();
				//game.Run();
			}
		}

		if (currentTime - prevTime >= 1000) {
			Utility::OutputDebug_Number((float)frCnt, hWnd);
			frCnt = 0;
			prevTime = currentTime;
		}
	}
	timeEndPeriod(1);
	FxManager::GetpInstance().ReleaseEffect("Shader\\BasicShader.fx");

	return (int)msg.wParam;
}