#ifndef SOUNDBUFFERMANAGER_H
#define SOUNDBUFFERMANAGER_H

#include<map>
#include<string>
#include<dsound.h>

class SoundBufferManager{
public:
	static SoundBufferManager& GetInstance();

	bool LoadWaveFile(const char* fileName);

	void CancelSound(std::string fileName);

	void PlayBackSound(std::string fileName, bool isLoop);

	void StopSound(std::string fileName);
private:
	static SoundBufferManager* m_pInstance;
	SoundBufferManager();
	~SoundBufferManager();

	std::map<std::string, IDirectSoundBuffer8*> m_PtrDirectSoundBuffers;

	SoundBufferManager(const SoundBufferManager&);
	void operator =(const SoundBufferManager&);
};
#endif