/**
 * @file	MaterialBase.h
 * @brief	MaterialBase�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef MATERIALBASE_H
#define MATERIALBASE_H

#include<d3dx9.h>
#include"ObjectBase.h"

class MaterialBase :public ObjectBase{
public:
	MaterialBase(D3DXVECTOR3& pos, D3DXVECTOR3& normalVec):
		m_Pos(pos),
		m_NormalVec(normalVec)
	{}
	MaterialBase(D3DXVECTOR3& pos) { m_Pos = pos; }

	virtual ~MaterialBase() {};

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3 m_NormalVec;	//!�����x�N�g��

	D3DXHANDLE m_World;
	D3DXHANDLE m_View;
	D3DXHANDLE m_Proj;
	D3DXHANDLE m_Light;
	//Player��Enemy���ƂɈ��������
	D3DXHANDLE		m_Technique;	//!< �e�N�j�b�N�n���h��.
};
#endif