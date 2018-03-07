/**
 * @file	GimmickBase.h
 * @brief	GimmickBaseクラスのヘッダ
 * @author	shiraishi
 */
#ifndef GIMMICKBASE_H
#define GIMMICKBASE_H

#include"MaterialBase.h"

class GimmickBase :public MaterialBase {
public:
	enum struct GIMMICK_KIND {
		FENCE, //!柵
		MAX
	};

	GimmickBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec, GIMMICK_KIND kind):
		MaterialBase(pos,normalVec),
		m_Kind(kind)
	{}

	virtual ~GimmickBase() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	const GIMMICK_KIND m_Kind;
};
#endif