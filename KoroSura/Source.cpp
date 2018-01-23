#include"Lib.h"
#include"Common.h"
#include"ObjectBase.h"
#include"Shape.h"
#include"ColliderManager.h"
#include"BoxCollider.h"

class Chip: public ObjectBase{
public:
	Chip(const D3DXVECTOR3& pos) 
	{
		m_Box.SetPos(pos);
		m_Box.SetDirect(0, D3DXVECTOR3(1, 0, 0));
		m_Box.SetDirect(1, D3DXVECTOR3(0, 1, 0));
		m_Box.SetDirect(2, D3DXVECTOR3(0, 0, 1));
		m_Box.SetLength(0, 3.0);
		m_Box.SetLength(1, 3.0);
		m_Box.SetLength(2, 3.0);

		m_Collider = new BoxCollider("aaa", this, &m_Box, std::bind(&Chip::collideeeee, this), 0x01, 0x11);
		ColliderManager::GetInstance().Register(m_Collider, 0);
	};
	virtual ~Chip() {};

	virtual void Update()
	{
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::ON) {
			m_Box.SetPos(m_Box.GetPos() + m_Box.GetDirect(3)*speed);
		}
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::DOWN) == Utility::BUTTON_STATE::ON) {
			m_Box.SetPos(m_Box.GetPos() - m_Box.GetDirect(3)*speed);
		}
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::RIGHT) == Utility::BUTTON_STATE::ON) {
			m_Box.SetPos(m_Box.GetPos() + m_Box.GetDirect(1)*speed);
		}
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::ON) {
			m_Box.SetPos(m_Box.GetPos() - m_Box.GetDirect(1)*speed);
		}

		Lib::GetInstance().TransformWorld(m_Box.GetPos());
	}

	virtual void Draw()
	{
		Lib::GetInstance().Render("Chips.x");
	}

private:
	const float speed = 0.1;
	Shape::OBB m_Box;
	BoxCollider* m_Collider;

	void collideeeee() {
		int a = 0;
	}
};

class Camera : public ObjectBase {
public:
	Camera(const D3DXVECTOR3& pos)
	{
		m_Pos = pos;
		m_DirectionVec = D3DXVECTOR3(1.0, 0.0, 0.0);
	};
	virtual ~Camera() {};

	virtual void Update()
	{
		const Utility::MouseData* pMouse = Lib::GetInstance().GetMouseData();
		D3DXVECTOR3 tmp = m_Pos;

		static float a = pMouse->Movement.x*0.01;
		static float b = pMouse->Movement.y*0.01;

		a += pMouse->Movement.x*0.01;
		b += pMouse->Movement.y*0.01;

		Lib::GetInstance().GetLookatPos(&tmp, 1.0, a, b);
		m_DirectionVec = tmp - m_Pos;
		tmp = m_DirectionVec;
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::W) == Utility::BUTTON_STATE::ON) {
			m_Pos += m_DirectionVec*speed;
		}
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::A) == Utility::BUTTON_STATE::ON) {
			m_Pos += *Lib::GetInstance().GetLookatPos(&tmp, 1.0, -90.0f, 0.0f)*speed;
		}
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::S) == Utility::BUTTON_STATE::ON) {
			m_Pos+= (-m_DirectionVec)*speed;
		}
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::D) == Utility::BUTTON_STATE::ON) {
			m_Pos += *Lib::GetInstance().GetLookatPos(&tmp, 1.0, 90.0f, 0.0f)*speed;
		}
	}

	virtual void Draw()
	{
		D3DXVECTOR3 lookAtPos = m_Pos + m_DirectionVec;
		Lib::GetInstance().TransformView(m_Pos, lookAtPos, D3DXVECTOR3(0.0, 1.0, 0.0));
		Lib::GetInstance().TransformProjection();
	}

private:
	const float speed = 1.5;

	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3 m_DirectionVec;
};

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

	Lib::GetInstance().LoadXFile("Chips.x");

	Chip chip1(D3DXVECTOR3(2, 0, 0));
	Chip chip2(D3DXVECTOR3(2, 0, 0));
	Camera camera(D3DXVECTOR3(0.0, 0.0, 0.0));

	Lib::GetInstance().SetRenderState3D();

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
				Lib::GetInstance().UpdateMouse();

				chip1.Update();
				camera.Update();

				ColliderManager::GetInstance().Collide();

				Lib::GetInstance().StartRender();
				camera.Draw();
				chip1.Draw();
				chip2.Draw();

				Lib::GetInstance().EndRender();
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