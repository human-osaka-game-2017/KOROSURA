#include"Lib.h"
#include"Common.h"
#include"SceneManager.h"
#include "FBXModel.h"
#include "DirectGraphics.h"
#include "Renderer.h"
#include "ModelManager.h"
#include "Shader.h"
#include "Effect.h"

//Player��Enemy���ƂɈ��������
D3DXHANDLE		g_Technique;	//!< �e�N�j�b�N�n���h��.


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_KEYDOWN:        // �L�[�������ꂽ�Ƃ�
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

	//Window�̓o�^
	RegisterClassEx(&Wndclass);

	//Window�̐���
	hWnd = CreateWindow(
		TEXT("WINDOW"),								//�E�B���h�E�̃N���X��
		"KOROSURA", 							//�E�B���h�E�̃^�C�g��
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,			//�E�B���h�E�X�^�C��
		CW_USEDEFAULT,								// �E�B���h�E�̉������̈ʒux
		CW_USEDEFAULT,								// �E�B���h�E�̏c�����̈ʒuy
		WINDOW_WIDTH,								// Width�i���j
		WINDOW_HEIGHT,								// Height�i�����j
		NULL,
		NULL,
		hInstance,							// �A�v���P�[�V�����C���X�^���X�̃n���h��
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
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\sky.fbx");

	D3DXHANDLE World;
	D3DXHANDLE View;
	D3DXHANDLE Proj;
	D3DXHANDLE Light;
	//////////////////////////////////////////////////////////////////////////////////
	//sample�Œu���Ă���
	//////////////////////////////////////////////////////////////////////////////////
	FxManager::GetpInstance().CreateEffect("Shader\\BasicShader.fx");
	//�e�N�j�b�N�n���h���̎擾
	//Effect���Ƃɂ��΂���
	g_Technique = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetTechniqueByName("Basic");
	World = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL,"World");
	View = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "View");
	Proj = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Proj");
	Light = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Light");


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
				//���[���h�g�����X�t�H�[���i��΍��W�ϊ��j
				Lib::GetInstance().TransformWorld(D3DXVECTOR3(0, 0, 0));
				Lib::GetInstance().TransformView(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 2), D3DXVECTOR3(0, 1, 0));
				Lib::GetInstance().TransformProjection(45.0f, WINDOW_WIDTH / WINDOW_HEIGHT,1.0f,20000.0f);
				//�ϊ��s��̎擾
				//Effect���Ƃɂ��΂���
				D3DXMATRIX WorldMatrix;
				(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix);
				Lib::GetInstance().TransformWorld(D3DXVECTOR3(200, 0, 0));
				D3DXMATRIX WorldMatrix2;
				(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_WORLD, &WorldMatrix2);
				D3DXMATRIX ViewMatrix;
				(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
				D3DXMATRIX ProjMatrix;
				(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);

				// �萔�̐ݒ�
				//Effect���Ƃɂ��΂���
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(World, &WorldMatrix);
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(View, &ViewMatrix);
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(Proj, &ProjMatrix);
				//���C�g�̌���
				static D3DXVECTOR4 LightDir = D3DXVECTOR4(1, 0, 0, 0);
				LightDir.x -= 0.01f;
				LightDir.y -= 0.02f;

				//�萔�̐ݒ�
				//Effect���Ƃɂ��΂���
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetVector(Light, &LightDir);
				Renderer::GetInstance().StartRender();
				// �V�F�[�_�[�p�X�̊J�n.
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
				ModelManager::GetInstance().Draw();
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(World, &WorldMatrix2);
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->BeginPass();
				//ModelManager::GetInstance().Draw();
				FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->EndPass();
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