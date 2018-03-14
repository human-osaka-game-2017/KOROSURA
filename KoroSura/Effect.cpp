#include"Effect.h"
#include"DirectGraphics.h"
#include"DirLightSource.h"

Effect::Effect(std::string FxPath)
{
	Effect::LoadFxFile(FxPath);

	m_Technique = m_Effect->GetParameterByName(NULL, "Basic");
	m_World		= m_Effect->GetParameterByName(NULL, "World");
	m_View		= m_Effect->GetParameterByName(NULL, "View");
	m_Proj		= m_Effect->GetParameterByName(NULL, "Proj");
	m_Light		= m_Effect->GetParameterByName(NULL, "Light");
	m_Color		= m_Effect->GetParameterByName(NULL, "Color");
}

void Effect::LoadFxFile(std::string fxfilePath)
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

void Effect::BeginPass(int technique)
{
	// シェーダーパスの開始.
	m_Effect->Begin(NULL, 0);
	m_Effect->BeginPass(technique);
}

void Effect::EndPass()
{
	m_Effect->EndPass();
	m_Effect->End();
}

void Effect::SetWorldMatrix(D3DXMATRIX* matrix)
{
	m_Effect->SetMatrix(m_World, matrix);
}

void Effect::SetViewMatrix(D3DXMATRIX* matrix)
{
	m_Effect->SetMatrix(m_View, matrix);
}

void Effect::SetProjMatrix(D3DXMATRIX* matrix)
{
	m_Effect->SetMatrix(m_Proj, matrix);
}
void Effect::SetColor(FBXLoader::Color_RGB color,float alpha)
{
	D3DXVECTOR4 tmp = D3DXVECTOR4(color.red, color.blue, color.green, alpha);
	m_Effect->SetVector(m_Color, &tmp);
}

void Effect::SetLightVector()
{
	m_Effect->SetVector(m_Light, &DirLightSource::GetpInstance().GetlightDir());
}