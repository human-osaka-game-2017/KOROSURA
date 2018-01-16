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
	// COMの初期化
	CoInitialize(NULL);

	//サウンドデバイスの作成
	DirectSoundCreate8(NULL, &m_pDirectSound, NULL);

	//協調レベルの設定
	m_pDirectSound->SetCooperativeLevel(hWnd, DSSCL_NORMAL);
}


DirectSound::~DirectSound()
{
}


IDirectSound8** DirectSound::GetDevice() {
	return &m_pDirectSound;
}