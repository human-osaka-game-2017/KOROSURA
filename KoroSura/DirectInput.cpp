#include"DirectInput.h"

#define BUFFER_SIZE  64

DirectInput* DirectInput::pInstance = nullptr;

void DirectInput::CrateInstance(HWND hWnd, HINSTANCE hInstance){
	if (pInstance == nullptr) {
		pInstance = new DirectInput(hWnd, hInstance);
	}
}

DirectInput& DirectInput::GetInstance() {
	if (pInstance == nullptr) {
		MessageBox(0, "DirectInputインスタンスが生成されていません", NULL, MB_OK);
	}
	return *pInstance;
}

DirectInput::DirectInput(HWND hWnd, HINSTANCE hInstance){
	//DirectInputの生成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDInput, NULL)))
	{
		MessageBox(0, "DirectInputの作成に失敗しました", NULL, MB_OK);
	}

	//キーボードの初期化
	if (FAILED(m_pDInput->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL)))
	{
		MessageBox(0, "DirectInputキーボードデバイスの作成に失敗しました", NULL, MB_OK);
	}

	//データフォーマット
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(0, "DirectInputキーボードデータフォーマットに失敗しました", NULL, MB_OK);
	}

	//協調レベル
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		MessageBox(0, "DirectInputキーボード協調レベルの設定に失敗しました", NULL, MB_OK);
	}
	m_pKeyDevice->Acquire();

	//マウスの初期化
	if (FAILED(m_pDInput->CreateDevice(GUID_SysMouse,
		&m_pMouseDevise, NULL)))
	{
		MessageBox(0, "DirectInputマウスデバイスの作成に失敗しました", NULL, MB_OK);
	}

	//データフォーマット
	if (FAILED(m_pMouseDevise->SetDataFormat(&c_dfDIMouse)))
	{
		MessageBox(0, "DirectInptマウスデータフォーマットに失敗しました", NULL, MB_OK);
	}

	//協調レベル
	if (FAILED(m_pMouseDevise->SetCooperativeLevel(hWnd,DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		MessageBox(0, "DirectInputマウス協調レベルの設定に失敗しました", NULL, MB_OK);
	}

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(dipdw);
	dipdw.diph.dwHeaderSize = sizeof(dipdw.diph);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = DIPROPAXISMODE_REL;

	if (FAILED(m_pMouseDevise->SetProperty(DIPROP_AXISMODE, &dipdw.diph)))
	{
		MessageBox(0, "DirectInputマウスSetPropertyに失敗しました", NULL, MB_OK);
	}

	dipdw.dwData = BUFFER_SIZE;

	if (FAILED(m_pMouseDevise->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph)))
	{
		MessageBox(0, "DirectInputマウスSetPropertyに失敗しました", NULL, MB_OK);
	}

	m_pMouseDevise->Acquire();
}

DirectInput::~DirectInput(){
	m_pKeyDevice->Unacquire();
	
	m_pKeyDevice->Release();

	m_pMouseDevise->Unacquire();

	m_pMouseDevise->Release();
	
	m_pDInput->Release();

	delete pInstance;
}

void DirectInput::UpdateKey() {
	if (false != m_pKeyDevice->Acquire()) {
		BYTE diks[256] = { 0 };
		m_pKeyDevice->GetDeviceState(sizeof(diks), diks);
		for (int i = 0; i < KEY_KIND::MAX; i++) {
			KeyCheck((KEY_KIND)i, diks);
		}
	}
}

void DirectInput::UpdateMouse() {
	if (false != m_pMouseDevise->Acquire()) {
		DIMOUSESTATE dims;
		m_pMouseDevise->GetDeviceState(sizeof(DIMOUSESTATE), &dims);
		MouseCheck(dims);
	}
}

void DirectInput::KeyCheck(KEY_KIND keyKind, BYTE* pDiks) {

	int DIK = DikCheck(keyKind);
	static BUTTON_STATE preKey[KEY_KIND::MAX] = { BUTTON_STATE::OFF };

	if (pDiks[DIK] & 0x80)
	{
		if (preKey[keyKind] == BUTTON_STATE::OFF)
		{
			m_CurrentKey[keyKind] = BUTTON_STATE::PUSH;
			preKey[keyKind] = BUTTON_STATE::ON;
		}
		else
		{
			m_CurrentKey[keyKind] = BUTTON_STATE::ON;
			preKey[keyKind] = BUTTON_STATE::ON;
		}
	}
	else
	{
		if (preKey[keyKind] == BUTTON_STATE::ON)
		{
			m_CurrentKey[keyKind] = BUTTON_STATE::RELEASE;
			preKey[keyKind] = BUTTON_STATE::OFF;
		}
		else
		{
			m_CurrentKey[keyKind] = BUTTON_STATE::OFF;
			preKey[keyKind] = BUTTON_STATE::OFF;
		}
	}
}

void DirectInput::MouseCheck(const DIMOUSESTATE& dims) {
	static BUTTON_STATE left = BUTTON_STATE::OFF;
	static BUTTON_STATE right = BUTTON_STATE::OFF;

	if (dims.rgbButtons[0])
	{
		if (left == BUTTON_STATE::OFF) {
			m_Mouse.LeftMouse = BUTTON_STATE::PUSH;
			left = BUTTON_STATE::ON;
		}
		else {
			m_Mouse.LeftMouse = BUTTON_STATE::ON;
			left = BUTTON_STATE::ON;
		}
	}
	else
	{
		if (left == BUTTON_STATE::OFF) {
			m_Mouse.LeftMouse = BUTTON_STATE::OFF;
			left = BUTTON_STATE::OFF;
		}
		else {
			m_Mouse.LeftMouse = BUTTON_STATE::RELEASE;
			left = BUTTON_STATE::OFF;
		}
	}

	if (dims.rgbButtons[1])
	{
		if (right == BUTTON_STATE::OFF) {
			m_Mouse.RightMouse = BUTTON_STATE::PUSH;
			right = BUTTON_STATE::ON;
		}
		else {
			m_Mouse.RightMouse = BUTTON_STATE::ON;
			right = BUTTON_STATE::ON;
		}
	}
	else
	{
		if (left == BUTTON_STATE::OFF) {
			m_Mouse.RightMouse = BUTTON_STATE::OFF;
			right = BUTTON_STATE::OFF;
		}
		else {
			m_Mouse.RightMouse = BUTTON_STATE::RELEASE;
			right = BUTTON_STATE::OFF;
		}
	}

	m_Mouse.Dim_x = dims.lX;
	
	m_Mouse.Dim_y = dims.lY;
	
	m_Mouse.Dim_z = dims.lZ;
}

int DirectInput::DikCheck(KEY_KIND keyKind) {
	int DIK;
	switch (keyKind) {
	case KEY_KIND::LEFT:
		DIK = DIK_LEFT;
		break;
	case KEY_KIND::RIGHT:
		DIK = DIK_RIGHT;
		break;
	case KEY_KIND::UP:
		DIK = DIK_UP;
		break;
	case KEY_KIND::DOWN:
		DIK = DIK_DOWN;
		break;
	case KEY_KIND::KEY_1:
		DIK = DIK_1;
		break;
	case KEY_KIND::KEY_2:
		DIK = DIK_2;
		break;
	case KEY_KIND::KEY_3:
		DIK = DIK_3;
		break;
	case KEY_KIND::KEY_4:
		DIK = DIK_4;
		break;
	case KEY_KIND::KEY_5:
		DIK = DIK_5;
		break;
	case KEY_KIND::KEY_6:
		DIK = DIK_6;
		break;
	case KEY_KIND::KEY_7:
		DIK = DIK_7;
		break;
	case KEY_KIND::KEY_8:
		DIK = DIK_8;
		break;
	case KEY_KIND::KEY_9:
		DIK = DIK_9;
		break;
	case KEY_KIND::KEY_0:
		DIK = DIK_0;
		break;
	case KEY_KIND::A:
		DIK = DIK_A;
		break;
	case KEY_KIND::B:
		DIK = DIK_B;
		break;
	case KEY_KIND::C:
		DIK = DIK_C;
		break;
	case KEY_KIND::D:
		DIK = DIK_D;
		break;
	case KEY_KIND::E:
		DIK = DIK_E;
		break;
	case KEY_KIND::F:
		DIK = DIK_F;
		break;
	case KEY_KIND::G:
		DIK = DIK_G;
		break;
	case KEY_KIND::H:
		DIK = DIK_H;
		break;
	case KEY_KIND::I:
		DIK = DIK_I;
		break;
	case KEY_KIND::J:
		DIK = DIK_J;
		break;
	case KEY_KIND::K:
		DIK = DIK_K;
		break;
	case KEY_KIND::L:
		DIK = DIK_L;
		break;
	case KEY_KIND::M:
		DIK = DIK_M;
		break;
	case KEY_KIND::N:
		DIK = DIK_N;
		break;
	case KEY_KIND::O:
		DIK = DIK_O;
		break;
	case KEY_KIND::P:
		DIK = DIK_P;
		break;
	case KEY_KIND::Q:
		DIK = DIK_Q;
		break;
	case KEY_KIND::R:
		DIK = DIK_R;
		break;
	case KEY_KIND::S:
		DIK = DIK_S;
		break;
	case KEY_KIND::T:
		DIK = DIK_T;
		break;
	case KEY_KIND::U:
		DIK = DIK_U;
		break;
	case KEY_KIND::V:
		DIK = DIK_V;
		break;
	case KEY_KIND::W:
		DIK = DIK_W;
		break;
	case KEY_KIND::X:
		DIK = DIK_X;
		break;
	case KEY_KIND::Y:
		DIK = DIK_Y;
		break;
	case KEY_KIND::Z:
		DIK = DIK_Z;
		break;
	case KEY_KIND::SPACE:
		DIK = DIK_SPACE;
		break;
	case KEY_KIND::LSHIFT:
		DIK = DIK_LSHIFT;
		break;
	case KEY_KIND::RSHIFT:
		DIK = DIK_RSHIFT;
		break;
	case KEY_KIND::LCONTROL:
		DIK = DIK_LCONTROL;
		break;
	case KEY_KIND::RCONTROL:
		DIK = DIK_RCONTROL;
		break;
	case KEY_KIND::ESC:
		DIK = DIK_ESCAPE;
		break;
	case KEY_KIND::ENTER:
		DIK = DIK_RETURN;
		break;
	}
	return DIK;
}