/**
 * @file	PushEnterKeyLogo.h
 * @brief	PushEnterKeyLogo�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef PUSHENTERKEYLOGO_H
#define PUSHENTERKEYLOGO_H

#include<functional>
#include "ObjectBase.h"
#include"Utility.h"

class Fader;

 /**
  * @brief		PushEnterKey�̃N���X
  * @details	"PushEnterKey"���t�F�[�h�C���A�E�g�����Ȃ���`�悵�A����L�[�������ꂽ��ʒm����N���X
  */
class PushEnterKeyLogo :public ObjectBase{
public:
	/**
	 * @brief PushEnterKeyLogo�̃R���X�g���N�^
	 * @param[in]	function	����L�[�������ꂽ�Ƃ��ɌĂ΂��֐�
	 */
	PushEnterKeyLogo(std::function<void()> function);

	/*** @brief PushEnterKeyLogo�̃f�X�g���N�^*/
	virtual ~PushEnterKeyLogo();

	/*** @brief PushEnterKeyLogo�̃A�b�v�f�[�g�֐�*/
	virtual void Update();

	/*** @brief PushEnterKeyLogo�̕`��֐�*/
	virtual void Draw();

private:
	void NextCharPos(Utility::CUSTOMVERTEX vertex[]);

	const D3DXVECTOR2 m_Pos;

	Fader* m_pFader;
	std::function<void()> m_Function;
};
#endif
