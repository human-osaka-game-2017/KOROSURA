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
	// コンパイルエラーの場合はエラーを表示して終了
	if (effect == NULL)
	{
		MessageBox(0, "Fxファイル読み込みで失敗しました", "", MB_OK);
		MessageBoxA(NULL, (char*)error->GetBufferPointer(), "ERROR", MB_OK);
	}
	m_Effect = effect;
}

void Effect::BeginPass()
{
	// シェーダーパスの開始.
	m_Effect->Begin(NULL, 0);
	m_Effect->BeginPass(0);
}
void Effect::EndPass()
{
	m_Effect->EndPass();
	m_Effect->End();
}