#ifndef SHAPE_H
#define SHAPE_H

#include<d3dx9.h>
#include"ObjectBase.h"

namespace Shape {

	enum SHAPE_ID {
		SQUARE,	//2D �l�p�`
		CIRCLE,	//2D �~
		BOX,	//3D ������
		SPHERE,	//3D ��
	};

	//class OBB: public ObjectBase {
	//public:
	//	OBB();
	//	virtual ~OBB(){}

	//	virtual void Update() = 0;
	//	virtual void Draw() = 0;

	//	D3DXVECTOR3& GetDirect(int elem);   // �w�莲�ԍ��̕����x�N�g�����擾
	//	FLOAT GetLen(int elem);				// �w�莲�����̒������擾
	//	D3DXVECTOR3& GetPos();				// �ʒu���擾
	//	void SetDirect(int elem, float deg);
	//	void Rotation(int elem, float deg);

	//protected:
	//	D3DXVECTOR3 m_Pos;              // �ʒu
	//	D3DXVECTOR3 m_NormaDirect[3];   // �����x�N�g��
	//	FLOAT m_fLength[3];             // �e�������̒���
	//};
}

#endif