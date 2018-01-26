/*!
 * @file DirectInput.h
 * @brief DirectInput(�V���O���g��)�N���X�̃w�b�_�t�@�C��
 * @author shiraishi
 */

#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H

#include<dinput.h>
#include"Utility.h"

/*** �_�C���N�g�C���v�b�g�N���X*/
class DirectInput{
public:
	/*!
	 * �C���X�^���X�̐����Ǝ擾
	 * @param	hWnd		�E�B���h�E�̃n���h��
	 * @param	hInstance	�C���X�^���X�n���h��
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
	Utility::BUTTON_STATE GetKeyState(Utility::KEY_KIND keyKind) {
		return m_CurrentKey[static_cast<int>(keyKind)];
	}

	/*!
	* �}�E�X�̏�Ԃ��擾
	* @return �}�E�X�̏��
	*/
	const Utility::MouseData* GetMouseData() {
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
	
	Utility::BUTTON_STATE m_CurrentKey[static_cast<int>(Utility::KEY_KIND::MAX)];
	Utility::MouseData m_Mouse;

	int DikCheck(Utility::KEY_KIND keyKind);
	void KeyCheck(Utility::KEY_KIND keyKind, BYTE* pDiks);
	void MouseCheck(const DIMOUSESTATE& dims);

	DirectInput(const DirectInput&);
	void operator =(const DirectInput&);
};
#endif