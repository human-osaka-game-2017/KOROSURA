#include "DirectSound.h"

DirectSound* DirectSound::m_pInstance = nullptr;

void DirectSound::CreateInstance(HWND hWnd) {
	if (m_pInstance == nullptr) {
		m_pInstance = new DirectSound(hWnd);
	}
}

DirectSound& DirectSound::GetInstance() {
	return *m_pInstance;
}

DirectSound::DirectSound(HWND hWnd){
	// COM�̏�����
	CoInitialize(NULL);

	//�T�E���h�f�o�C�X�̍쐬
	DirectSoundCreate8(NULL, &m_pDirectSound, NULL);

	//�������x���̐ݒ�
	m_pDirectSound->SetCooperativeLevel(hWnd, DSSCL_NORMAL);
}


DirectSound::~DirectSound()
{
}


IDirectSound8** DirectSound::GetDevice() {
	return &m_pDirectSound;
}