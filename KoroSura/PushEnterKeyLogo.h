/**
 * @file	PushEnterKeyLogo.h
 * @brief	PushEnterKeyLogoクラスのヘッダ
 * @author	shiraishi
 */
#ifndef PUSHENTERKEYLOGO_H
#define PUSHENTERKEYLOGO_H

#include<functional>
#include "ObjectBase.h"
#include"Utility.h"

class Fader;

 /**
  * @brief		PushEnterKeyのクラス
  * @details	"PushEnterKey"をフェードインアウトさせながら描画し、決定キーが押されたら通知するクラス
  */
class PushEnterKeyLogo :public ObjectBase{
public:
	/**
	 * @brief PushEnterKeyLogoのコンストラクタ
	 * @param[in]	function	決定キーが押されたときに呼ばれる関数
	 */
	PushEnterKeyLogo(std::function<void()> function);

	/*** @brief PushEnterKeyLogoのデストラクタ*/
	virtual ~PushEnterKeyLogo();

	/*** @brief PushEnterKeyLogoのアップデート関数*/
	virtual void Update();

	/*** @brief PushEnterKeyLogoの描画関数*/
	virtual void Draw();

private:
	void NextCharPos(Utility::CUSTOMVERTEX vertex[]);

	const D3DXVECTOR2 m_Pos;

	Fader* m_pFader;
	std::function<void()> m_Function;
};
#endif
