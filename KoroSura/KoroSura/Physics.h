#ifndef PHYSICS_H
#define PHYSICS_H

#include<d3dx9.h>

class Physics{
public:
	Physics();
	~Physics();

	/**
	 * @brief			�]��������x�N�g�����擾
	 * @param[out]		fallVec
	 * @param[in]		currentPos		�]���镨�̂̍��W
	 * @return			D3DXVECTOR3*	������
	 * @details			GetRollLength�֐��̖߂�l���|����Ɠ]����ʒu�ɂȂ�
	 */
	D3DXVECTOR3* GetRollVec(D3DXVECTOR3* rollVec, const D3DXVECTOR3& currentPos);

	/**
	 * @brief			�]���鋗�����擾
	 * @return			D3DXVECTOR3*	����
	 * @details			GetRollVec�֐��̖߂�l���|����Ɠ]����ʒu�ɂȂ�
	 */
	float GetRollVelocity();

private:
	float m_Velocity = 0;
};
#endif