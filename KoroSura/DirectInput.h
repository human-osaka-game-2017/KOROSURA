/*!
 * @file DirectInput.h
 * @brief DirectInput(シングルトン)クラスのヘッダファイル
 * @author shiraishi
 */

#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H

#include<dinput.h>
#include"Utility.h"

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
	Utility::BUTTON_STATE GetKeyState(Utility::KEY_KIND keyKind) {
		return m_CurrentKey[static_cast<int>(keyKind)];
	}

	/*!
	* マウスの状態を取得
	* @return マウスの状態
	*/
	const Utility::MouseData* GetMouseData() {
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
	
	Utility::BUTTON_STATE m_CurrentKey[static_cast<int>(Utility::KEY_KIND::MAX)];
	Utility::MouseData m_Mouse;

	int DikCheck(Utility::KEY_KIND keyKind);
	void KeyCheck(Utility::KEY_KIND keyKind, BYTE* pDiks);
	void MouseCheck(const DIMOUSESTATE& dims);

	DirectInput(const DirectInput&);
	void operator =(const DirectInput&);
};
#endif