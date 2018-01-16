/*!
 * @file DirectInput.h
 * @brief DirectInput(�V���O���g��)�N���X�̃w�b�_�t�@�C��
 * @author shiraishi
 */

#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H

#include<dinput.h>
#include"Utility.h"

using Utility::BUTTON_STATE;
using Utility::KEY_KIND;
using Utility::MOUSE_DATA;

/*!
 * �_�C���N�g�C���v�b�g�N���X
 */
class DirectInput{
public:
	/*!
	* �C���X�^���X�̐����Ǝ擾
	* @param hWnd �E�B���h�E�̃n���h��
	* @param hInstance  �C���X�^���X�n���h��
	*/
	static void CrateInstance(HWND hWnd, HINSTANCE hInstance);

	static DirectInput& GetInstance();

	/*!
	* �L�[�{�[�h�̃A�b�v�f�[�g
	*/
	void UpdateKey();

	/*!
	* �}�E�X�̃A�b�v�f�[�g
	*/
	void UpdateMouse();

	/*!
	* �L�[�{�[�h�̏�Ԃ��擾
	* @param keyKind �L�[�{�[�h����ID
	* @return �L�[�{�[�h�̃{�^���̏��
	*/
	BUTTON_STATE GetKeyState(KEY_KIND keyKind) {
		return m_CurrentKey[keyKind];
	}

	/*!
	* �}�E�X�̏�Ԃ��擾
	* @return �}�E�X�̏��
	*/
	const MOUSE_DATA* GetMouseData() {
		return &m_Mouse;
	}

private:
	/*!
	* ���g�̃C���X�^���X
	*/
	static DirectInput* pInstance;

	/*!
	* �_�C���N�g�C���v�b�g�̃R���X�g���N�^
	* @param hWnd �E�B���h�E�̃n���h��
	* @param hInstance  �C���X�^���X�n���h��
	*/
	DirectInput(HWND hWnd, HINSTANCE hInstance);

	/*!
	* �_�C���N�g�C���v�b�g�̃f�X�g���N�^
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