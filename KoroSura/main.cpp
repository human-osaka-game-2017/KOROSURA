#include"Lib.h"
#include"Common.h"
#include"SceneManager.h"
#include "FBXModel.h"
#include "DirectGraphics.h"
#include "Renderer.h"
#include "ModelManager.h"
#include "Shader.h"

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


	SceneManager game;

	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\house_red.fbx");

	D3DXHANDLE World;
	D3DXHANDLE View;
	D3DXHANDLE Proj;
	D3DXHANDLE Light;
	//////////////////////////////////////////////////////////////////////////////////
	//sampleで置いている
	//////////////////////////////////////////////////////////////////////////////////
	ShaderManager shaderManager;

	shaderManager.LoadingShader("Shader\\BasicShader.fx");
	//テクニックハンドルの取得
	//Effectごとにやればいい
	g_Technique = shaderManager.GetEffect("Shader\\BasicShader.fx")->GetTechniqueByName("Basic");
	//Shader内定数のハンドル取得
	//Effectごとにやればいい
	World = shaderManager.GetEffect("Shader\\BasicShader.fx")->GetParameterByName(NULL, "World");
	View = shaderManager.GetEffect("Shader\\BasicShader.fx")->GetParameterByName(NULL, "View");
	Proj = shaderManager.GetEffect("Shader\\BasicShader.fx")->GetParameterByName(NULL, "Proj");
	Light = shaderManager.GetEffect("Shader\\BasicShader.fx")->GetParameterByName(NULL, "Light");


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
				Lib::GetInstance().TransformView(D3DXVECTOR3(450, 800, 400), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 1, 0));
				Lib::GetInstance().TransformProjection(45.0f, WINDOW_WIDTH / WINDOW_HEIGHT,1.0f,5000.0f);
				//変換行列の取得
				//Effectごとにやればいい
				D3DXMATRIX WorldMatrix;
				(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
				D3DXMATRIX ViewMatrix;
				(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
				D3DXMATRIX ProjMatrix;
				(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);

				// 定数の設定
				//Effectごとにやればいい
				shaderManager.GetEffect("Shader\\BasicShader.fx")->SetMatrix(World, &WorldMatrix);
				shaderManager.GetEffect("Shader\\BasicShader.fx")->SetMatrix(View, &ViewMatrix);
				shaderManager.GetEffect("Shader\\BasicShader.fx")->SetMatrix(Proj, &ProjMatrix);
				//ライトの向き
				static D3DXVECTOR4 LightDir = D3DXVECTOR4(1, 0, 0, 0);
				LightDir.x -= 0.01f;
				LightDir.y -= 0.02f;

				//定数の設定
				//Effectごとにやればいい
				shaderManager.GetEffect("Shader\\BasicShader.fx")->SetVector(Light, &LightDir);
				Renderer::GetInstance().StartRender();
				// シェーダーパスの開始.
				shaderManager.GetEffect("Shader\\BasicShader.fx")->Begin(NULL, 0);
				shaderManager.GetEffect("Shader\\BasicShader.fx")->BeginPass(0);
				ModelManager::GetInstance().Draw();
				shaderManager.GetEffect("Shader\\BasicShader.fx")->EndPass();
				shaderManager.GetEffect("Shader\\BasicShader.fx")->End();
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
	shaderManager.ReleaseShader("Shader\\BasicShader.fx");

	return (int)msg.wParam;
}