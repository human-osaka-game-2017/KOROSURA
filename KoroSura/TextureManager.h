#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include"Utility.h"
#include<map>

using std::string;
using Utility::PICTURE_INFO;

class TextureManager {
public:	
	static void CreateInstance();
	static TextureManager& GetInstance();

	//�e�L�X�`���������܂�
	void CancelTexture(const char* fileName);

	//png,jpeg�t�@�C������f�[�^��ǂݍ��݂܂�
	//������ �t�@�C���ւ̃p�X
	//������ ���̃e�L�X�`����ID
	HRESULT LoadPictureFile(const char* fileName, int width, int height, bool canSemitransparent);

private:
	static TextureManager* pInstance;
	TextureManager();
	~TextureManager();

	std::map<string, PICTURE_INFO> m_pTextures;

	TextureManager(const TextureManager&);
	void operator =(const TextureManager&);

public:
	const PICTURE_INFO& GetPictureInfo(const char* fileName) {
		if (m_pTextures.find(fileName) != m_pTextures.end()) {
			return m_pTextures[fileName];
		}
		exit(1);
	}
};
#endif