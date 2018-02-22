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
	 * @return			D3DXVECTOR3*	第一引数
	 * @details			GetRollLength関数の戻り値を掛けると転がる位置になる
	 */
	D3DXVECTOR3* GetRollVec(D3DXVECTOR3* rollVec, const D3DXVECTOR3& currentPos);

	/**
	 * @brief			転がる距離を取得
	 * @return			D3DXVECTOR3*	距離
	 * @details			GetRollVec関数の戻り値を掛けると転がる位置になる
	 */
	float GetRollVelocity();

private:
	float m_Velocity = 0;
};
#endif