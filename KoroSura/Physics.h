#ifndef PHYSICS_H
#define PHYSICS_H

#include<d3dx9.h>

class Physics{
public:
	Physics();
	~Physics();

	/**
	 * @brief			転がる方向ベクトルを取得
	 * @param[out]		fallVec
	 * @param[in]		currentPos		転がる物体の座標
	 * @return			D3DXVECTOR3*	第二引数
	 */
	D3DXVECTOR3* GetFallVec(D3DXVECTOR3* fallVec, const D3DXVECTOR3& currentPos);

};
#endif