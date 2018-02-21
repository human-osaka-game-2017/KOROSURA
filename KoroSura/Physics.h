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
	 */
	D3DXVECTOR3* GetFallVec(D3DXVECTOR3* fallVec, const D3DXVECTOR3& currentPos);

};
#endif