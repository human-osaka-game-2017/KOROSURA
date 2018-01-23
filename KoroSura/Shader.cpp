#include "Shader.h"
#include "DirectGraphics.h"

bool ShaderManager::LoadingShader(std::string file_name)
{
	LPDIRECT3DDEVICE9* pDXDevice = DirectGraphics::GetInstance().GetDevice();

	LPD3DXEFFECT effect = NULL;
	LPD3DXBUFFER error;

	if (m_ShaderList[file_name] != NULL)
	{
		return true;
	}

	D3DXCreateEffectFromFileA(
		*pDXDevice,
		file_name.c_str(),
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
		MessageBox(0, "Shaderのファイル読み込みで失敗しました", "", MB_OK);
		MessageBoxA(NULL, (char*)error->GetBufferPointer(), "ERROR", MB_OK);
		return false;
	}
	m_ShaderList[file_name] = effect;
	return true;
}