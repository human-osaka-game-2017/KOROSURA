#include "SoundBufferManager.h"
#include"DirectSound.h"

SoundBufferManager* SoundBufferManager::m_pInstance = nullptr;

SoundBufferManager& SoundBufferManager::GetInstance() {
	if (m_pInstance == nullptr) {
		m_pInstance = new SoundBufferManager();
	}

	return *m_pInstance;
}

SoundBufferManager::SoundBufferManager(){
}

SoundBufferManager::~SoundBufferManager(){
	for (auto itr = m_PtrDirectSoundBuffers.begin(); itr != m_PtrDirectSoundBuffers.end(); ++itr) {
		itr->second->Release();
	}

	delete m_pInstance;
}

bool SoundBufferManager::LoadWaveFile(const char* fileName) {
	MMIOINFO mmioInfo;
	HMMIO hMmio = NULL;

	// Waveファイルオープン
	memset(&mmioInfo, 0, sizeof(MMIOINFO));
	hMmio = mmioOpen(const_cast<char*>(fileName), &mmioInfo, MMIO_READ);
	if (!hMmio) {
		return false; // ファイルオープン失敗
	}

	MMRESULT mmRes;

	//riffchunkの設定
	MMCKINFO riffChunk;
	riffChunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmRes = mmioDescend(hMmio, &riffChunk, NULL, MMIO_FINDRIFF);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}

	//formatchunkの設定
	MMCKINFO formatChunk;
	formatChunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmRes = mmioDescend(hMmio, &formatChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}

	DSBUFFERDESC dsBufferDesc;
	dsBufferDesc.dwSize = sizeof(DSBUFFERDESC);
	dsBufferDesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2;
	dsBufferDesc.dwReserved = 0;
	dsBufferDesc.lpwfxFormat = NULL;
	dsBufferDesc.guid3DAlgorithm = GUID_NULL;
	dsBufferDesc.lpwfxFormat = (WAVEFORMATEX*)malloc(sizeof(WAVEFORMATEX));

	//waveFormatEx構造体の設定
	DWORD fmsize = formatChunk.cksize;
	DWORD size = mmioRead(hMmio, (HPSTR)dsBufferDesc.lpwfxFormat, fmsize);
	if (size != fmsize) {
		mmioClose(hMmio, 0);
		return false;
	}

	mmioAscend(hMmio, &formatChunk, 0);

	//datachunkの設定
	MMCKINFO dataChunk;
	dataChunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmRes = mmioDescend(hMmio, &dataChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}

	//音データに設定
	//DWORD dwFileSize = mmioSeek(*hMmio, 0, SEEK_END);
	//mmioSeek(*hMmio, 0, SEEK_SET);
	char* pData = NULL;
	pData = (char*)malloc(sizeof(char)*dataChunk.cksize);
	size = mmioRead(hMmio, (HPSTR)pData, dataChunk.cksize);
	if (size != dataChunk.cksize) {
		free(pData);
		return false;
	}

	dsBufferDesc.dwBufferBytes = size;

	mmioClose(hMmio, 0);

	//セカンダリバッファの作成
	IDirectSound8** pDSDevice = DirectSound::GetInstance().GetDevice();
	IDirectSoundBuffer *ptmpBuf = 0;
	(*pDSDevice)->CreateSoundBuffer(&dsBufferDesc, &ptmpBuf, NULL);
	ptmpBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)&m_PtrDirectSoundBuffers[fileName]);//IDirectSoundBufferをIDirectSoundBuffer8に変更
	ptmpBuf->Release();

	// セカンダリバッファにWaveデータ書き込み
	LPVOID lpvWrite = 0;
	DWORD dwLength = 0;
	if (DS_OK == m_PtrDirectSoundBuffers[fileName]->Lock(0, 0, &lpvWrite, &dwLength, NULL, NULL, DSBLOCK_ENTIREBUFFER)) {
		memcpy(lpvWrite, pData, dwLength);
		m_PtrDirectSoundBuffers[fileName]->Unlock(lpvWrite, dwLength, NULL, 0);
	}

	free(pData);
	free(dsBufferDesc.lpwfxFormat);

	return true;
}

void SoundBufferManager::CancelSound(std::string fileName) {
	if (m_PtrDirectSoundBuffers[fileName] != nullptr) {
		m_PtrDirectSoundBuffers[fileName]->Release();
		m_PtrDirectSoundBuffers.erase(fileName);
	}
}

void SoundBufferManager::PlayBackSound(std::string fileName, bool isLoop) {
	m_PtrDirectSoundBuffers[fileName]->SetVolume(100);

	if (isLoop) {
		m_PtrDirectSoundBuffers[fileName]->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		m_PtrDirectSoundBuffers[fileName]->Play(0, 0, 0);
	}
}

void SoundBufferManager::StopSound(std::string fileName) {
	m_PtrDirectSoundBuffers[fileName]->Stop();
}