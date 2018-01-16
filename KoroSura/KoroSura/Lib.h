#ifndef LIB_H
#define LIB_H

#include<Windows.h>
#include<string>
#include"Utility.h"

class DirectGraphics;
class DirectInput;
class SoundBufferManager;
class Renderer;
class ModelManager;
class TextureManager;

class Lib {
public:
	static void CreateInstance(HWND hWnd, HINSTANCE hInstance);
	static Lib& GetInstance();

	void UpdateKey();

	void UpdateMouse();

	/*!
	* �L�[�{�[�h�̏�Ԃ��擾
	* @param keyKind �L�[�{�[�h����ID
	* @return �L�[�{�[�h�̃{�^���̏��
	*/
	Utility::BUTTON_STATE GetKeyState(Utility::KEY_KIND keyKind);

	/*!
	* �}�E�X�̏�Ԃ��擾
	* @return �}�E�X�̏��
	*/
	const Utility::MOUSE_DATA* GetMouseData();

	/*!
	* �o�^����Ă��郂�f���f�[�^�̍폜
	* @param fileName 
	*/
	void CancelModel(const char* fileName);

	/*!
	* X�t�@�C������f�[�^��o�^
	* @param fileName
	*/
	HRESULT LoadXFile(const char* fileName);

	/*!
	* 
	* @param fileName
	*/
	//��΍��W�ϊ����܂�
	//������ �`�悵�������W
	//������ Y���ł̉�](�x���j�i�f�t�H���g��0�j
	//��O���� X���ł̉�]�i�x���j�i�f�t�H���g��0�j
	//��l���� Z���ł̉�]�i�x���j�i�f�t�H���g��0�j
	//��܈��� �g�k���i�f�t�H���g��1.0�j
	void TransformWorld(const D3DXVECTOR3& pPos, float degHeading = 0.0f, float degPitch = 0.0f, float degBank = 0.0f, float scale = 1.0f);

	//���_���W�ϊ����܂�
	//������ �J�������W
	//��O���� Y���ł̃J�����̉�]�i�x���j
	//��l���� Z���ł̃J�����̉�]�i�x���j
	void TransformView(const D3DXVECTOR3& pCameraPos, const D3DXVECTOR3&  LookatPos, const D3DXVECTOR3& UpVec);

	D3DXVECTOR3* GetLookatPos(D3DXVECTOR3* pos, float length, float degHeading, float degBank);

	//�ˉe�ϊ����܂�
	//������ ����p�i�x���j�i�f�t�H���g��45�x�j
	//������ �A�X�y�N�g��i�f�t�H���g��1.0�j
	//��O���� ���ł���ŏ������i�f�t�H���g��1.0�j
	//��l���� ���ł���ő勗���i�f�t�H���g��100.0�j
	void TransformProjection(float angle = 45.0f, float aspectRatio = 1.0f, float mimDistance = 1.0f, float maxDistance = 100.0f);

	void SetRenderState2D();

	void SetRenderState3D();

	/*!
	* 3D��`�悷��O�ɕK���ĂԂ���
	*/
	void StartRender();

	/*!
	* 2D��`�悷��O�ɕK���ĂԂ���
	*/
	void StartDraw(int red = 0xff, int green = 0xff, int blue = 0xff);

	bool Draw(const D3DXVECTOR3& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const D3DXVECTOR2& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const Utility::CUSTOMVERTEX vertex[], const char* fileName);

	//�`��֐�
	//������ ���̃��b�V����ID
	bool Render(const char* fileName);

	//�`��I��
	void EndRender();
	void EndDraw();

	void TurnVertex_tu(Utility::CUSTOMVERTEX vertex[]);
	void TurnVertex_tv(Utility::CUSTOMVERTEX vertex[]);
	void ChangeScale(Utility::CUSTOMVERTEX vertex[], float magnifying);
	void TrimingVertex(Utility::CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight);
	void Rotation(Utility::CUSTOMVERTEX vertex[], float deg);

	//�e�L�X�`���������܂�
	void CancelTexture(const char* fileName);

	//png,jpeg�t�@�C������f�[�^��ǂݍ��݂܂�
	//������ �t�@�C���ւ̃p�X
	//������ ���̃e�L�X�`����ID
	HRESULT LoadPictureFile(const char* fileName, int width, int height, bool canSemitransparent = true);

	bool LoadWaveFile(const char* fileName);

	void CancelSound(std::string fileName);

	void PlayBackSound(std::string fileName, bool isLoop);

	void StopSound(std::string fileName);

private:
	static Lib* pInstance;
	Lib(HWND hWnd, HINSTANCE hInstance);
	~Lib();

	DirectGraphics* m_pDirectGraphics;
	DirectInput* m_pDirectInput;
	Renderer* m_pRenderer;
	ModelManager* m_pModelManager;
	TextureManager* m_pTextureManager;
	SoundBufferManager* m_pSoundBufferManager;

	Lib(const Lib&);
	void operator =(const Lib&);
};
#endif
