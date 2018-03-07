#ifndef CAMERA_H
#define CAMERA_H

#include<d3dx9.h>

class Camera {
public:
	Camera(D3DXVECTOR3* lookatpos);
	~Camera();

	void Update();

private:
	const float kDistance;
	const float kLookAtPosYOffset;
	bool m_FirstTime;

	D3DXVECTOR3		m_Pos;
	D3DXVECTOR3*	m_pLookatPos;
	D3DXVECTOR3		m_MovementMouse;
	//D3DXMATRIX*		m_pViewOut;
};
#endif