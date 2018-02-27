#ifndef CAMERA_H
#define CAMERA_H

#include<d3dx9.h>

class Camera{
public:
	Camera(D3DXVECTOR3& pos, D3DXVECTOR3* lookatpos);
	~Camera();

	void Update();

private:
	static const float m_distance;

	D3DXVECTOR3		m_Pos;
	D3DXVECTOR3*	m_LookatPos;
	D3DXVECTOR3		m_MovementMouse;
	D3DXMATRIX*		m_pViewOut;
};
#endif