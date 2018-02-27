#include "Effect.h"



Effect::Effect(std::string FxPath)
{
	Effect::LoadingFx(FxPath);
}
void Effect::LoadingFx(std::string fxfilePath)
{
	LPDIRECT3DDEVICE9* pDXDevice = DirectGraphics::GetInstance().GetDevice();

	LPD3DXEFFECT effect = NULL;
	LPD3DXBUFFER error;


	D3DXCreateEffectFromFileA(
		*pDXDevice,
		fxfilePath.c_str(),
		NULL,
		NULL,
		0,
		NULL,
		&effect,
		&error
	);
	// �R���p�C���G���[�̏ꍇ�̓G���[��\�����ďI��
	if (effect == NULL)
	{
		MessageBox(0, "Fx�t�@�C���ǂݍ��݂Ŏ��s���܂���", "", MB_OK);
		MessageBoxA(NULL, (char*)error->GetBufferPointer(), "ERROR", MB_OK);
	}
	m_Effect = effect;
}

void Effect::BeginPass()
{
	// �V�F�[�_�[�p�X�̊J�n.
	m_Effect->Begin(NULL, 0);
	m_Effect->BeginPass(0);
}
void Effect::EndPass()
{
	m_Effect->EndPass();
	m_Effect->End();
}