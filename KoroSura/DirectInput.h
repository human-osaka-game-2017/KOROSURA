/*!
 * @file DirectInput.h
 * @brief DirectInput(シングルトン)クラスのヘッダファイル
 * @author shiraishi
 */

#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H

#include<dinput.h>
#include"Utility.h"

using Utility::BUTTON_STATE;
using Utility::KEY_KIND;
using Utility::MOUSE_DATA;

/*** ダイレクトインプットクラス*/
class DirectInput{
public:
	/*!
	 * インスタンスの生成と取得
	 * @param	hWnd		ウィンドウのハンドル
	 * @param	hInstance	インスタンスハンドル
	 */
	static void CrateInstance(HWND hWnd, HINSTANCE hInstance);

	static DirectInput& GetInstance();

	/*!
	* キーボードのアップデート
	*/
	void UpdateKey();

	/*!
	* マウスのアップデート
	*/
	void UpdateMouse();

	/*!
	* キーボードの状態を取得
	* @param keyKind キーボード識別ID
	* @return キーボードのボタンの状態
	*/
	BUTTON_STATE GetKeyState(KEY_KIND keyKind) {
		return m_CurrentKey[keyKind];
	}

	/*!
	* マウスの状態を取得
	* @return マウスの状態
	*/
	const MOUSE_DATA* GetMouseData() {
		return &m_Mouse;
	}

private:
	/*!
	* 自身のインスタンス
	*/
	static DirectInput* pInstance;

	/*!
	* ダイレクトインプットのコンストラクタ
	* @param hWnd ウィンドウのハンドル
	* @param hInstance  インスタンスハンドル
	*/
	DirectInput(HWND hWnd, HINSTANCE hInstance);

	/*!
	* ダイレクトインプットのデストラクタ
	*/
	~DirectInput();

	LPDIRECTINPUT8 m_pDInput;
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;
	LPDIRECTINPUTDEVICE8 m_pMouseDevise;
	
	BUTTON_STATE m_CurrentKey[KEY_KIND::MAX];
	MOUSE_DATA m_Mouse;

	int DikCheck(KEY_KIND keyKind);
	void KeyCheck(KEY_KIND keyKind, BYTE* pDiks);
	void MouseCheck(const DIMOUSESTATE& dims);

	DirectInput(const DirectInput&);
	void operator =(const DirectInput&);
};
#endif