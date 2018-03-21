#include"Billboard.h"
#include"Camera.h"
#include"Lib.h"
#include"DirectGraphics.h"

Billboard* Billboard::pInstance = nullptr;

Billboard& Billboard::GetInstans() {
	if (pInstance == nullptr) {
		pInstance = new Billboard();
	}
	return *pInstance;
}

void Billboard::BillboardingTransform(D3DXVECTOR3 pos, float scale)
{
	//�ŏI�I�ȃ��[���h�g�����X�t�H�[���s��
	D3DXMATRIXA16 matWorld;
	//���s�ړ��p�s��
	D3DXMATRIXA16 matPosition;
	//�g�k�p�s��
	D3DXMATRIXA16 matScale;

	//�s��̏�����
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matPosition);
	D3DXMatrixIdentity(&matScale);

	//���[���h�g�����X�t�H�[���i��΍��W�ϊ��j
	//�g�k
	D3DXMatrixScaling(&matScale, scale, scale, scale);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matScale);

	D3DXMATRIX ViewMatrix;
	//���݂̃r���[�s��𓾂�
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	//��������r���[�̍s��ϊ��������Ȃ�
	D3DXMatrixInverse(&ViewMatrix, NULL, &ViewMatrix);


	D3DXMatrixMultiply(&matWorld, &matWorld, &ViewMatrix);
	//���s�ړ�
	D3DXMatrixTranslation(&matPosition, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

	//�����_�����O�d�l�̓o�^
	(*DirectGraphics::GetInstance().GetDevice())->SetTransform(D3DTS_WORLD, &matWorld);
}

