/**
 * @file	Shader.h
 * @brief	シェーダーを使った描画
 * @author	北川　翔馬
 */
//
//#ifndef SHADER_H
//#define SHADER_H
//
//#include <string>
//#include <map>
//
//#define INK_SIZE (0.008f) //! インクのサイズ
//#define INK_COLOR (D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f)) //! インクの色
//
//#define BASIC_SHADER_NAME ("Shader/BasicShader.fx") //! fxファイルの読み込み
//
//class ShaderManager {
//public:
//	bool LoadingShader(std::string file_name);
//	LPD3DXEFFECT GetEffect(std::string key) { return m_ShaderList[key]; }
//private:
//	std::map < std::string, LPD3DXEFFECT> m_ShaderList;
//};
//#endif