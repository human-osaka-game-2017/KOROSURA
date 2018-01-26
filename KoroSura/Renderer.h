#ifndef RENDERER_H
#define RENDERER_H

#include"Utility.h"

using Utility::CUSTOMVERTEX;

class Renderer {
public:
	static void CreateInstance();
	static Renderer& GetInstance();

	//��΍��W�ϊ����܂�
	//������ �`�悵�������W
	//������ Y���ł̉�](�x���j�i�f�t�H���g��0�j
	//��O���� X���ł̉�]�i�x���j�i�f�t�H���g��0�j
	//��l���� Z���ł̉�]�i�x���j�i�f�t�H���g��0�j
	//��܈��� �g�k���i�f�t�H���g��1.0�j
	void TransformWorld(const D3DXVECTOR3& pos, float degHeading = 0.0f, float degPitch = 0.0f, float degBank = 0.0f, float scale = 1.0f);

	//���_���W�ϊ����܂�
	//������ �J�������W
	//��O���� Y���ł̃J�����̉�]�i�x���j
	//��l���� Z���ł̃J�����̉�]�i�x���j
	void TransformView(const D3DXVECTOR3& cameraPos, const D3DXVECTOR3& lookatPos, const D3DXVECTOR3& upVec);

	D3DXVECTOR3* GetLookatPos(D3DXVECTOR3* pPos, float length, float degHeading, float degBank);

	//�ˉe�ϊ����܂�
	//������ ����p�i�x���j�i�f�t�H���g��45�x�j
	//������ �A�X�y�N�g��i�f�t�H���g��1.0�j
	//��O���� ���ł���ŏ������i�f�t�H���g��1.0�j
	//��l���� ���ł���ő勗���i�f�t�H���g��100.0�j
	void TransformProjection(float angle = 45.0f, float aspectRatio = 1.0f, float mimDistance = 1.0f, float maxDistance = 100.0f);

	//3D�`����n�߂鏀��
	void StartRender();

	//2D�`����n�߂鏀��
	void StartDraw(int red, int green, int blue);

	bool Draw(const D3DXVECTOR2& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const D3DXVECTOR3& pos, const char* fileName, float width, float height, float tu = 0.0f, float tv = 0.0f, float deg = 0.0f, float magnifying = 1.0f, DWORD color = 0xFFFFFFFF, bool flipHorizontal = false, bool flipVertical = false);
	bool Draw(const CUSTOMVERTEX vertex[], const char* fileName);

	//�`��֐�
	//������ ���̃��b�V����ID
	bool Render(const char* fileName);

	//�`��I��
	void EndRender();
	void EndDraw();

	void TurnVertex_tu(CUSTOMVERTEX vertex[]);
	void TurnVertex_tv(CUSTOMVERTEX vertex[]);
	void ChangeScale(CUSTOMVERTEX vertex[], float magnifying);
	void TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight);
	void Rotation(CUSTOMVERTEX vertex[], float deg);

private:
	static Renderer* pInstance;
	Renderer();
	~Renderer();

	LPDIRECT3DDEVICE9* m_pDXDevice;

	Renderer(const Renderer&);
	void operator =(const Renderer&);
};
#endif