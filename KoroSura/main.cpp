#include"Lib.h"
#include"Common.h"
#include"SceneManager.h"

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
	RECT rw, rc;
	GetWindowRect(hWnd, &rw);
	GetClientRect(hWnd, &rc);

	int new_width = (rw.right - rw.left) - (rc.right - rc.left) + WINDOW_WIDTH;
	int new_height = (rw.bottom - rw.top) - (rc.bottom - rc.top) + WINDOW_HEIGHT;

	SetWindowPos(hWnd, NULL, 0, 0, new_width, new_height, SWP_NOMOVE | SWP_NOZORDER);

	GetWindowRect(hWnd, &rw);
	GetClientRect(hWnd, &rc);

	ShowWindow(hWnd, SW_SHOW);
	ShowCursor(false);

	Lib::CreateInstance(hWnd, hInstance);
	SceneManager game;

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	DWORD prevTime = timeGetTime();
	DWORD currentTime;

	timeBeginPeriod(1);
	int frCnt = 0;

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
				game.Run();
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