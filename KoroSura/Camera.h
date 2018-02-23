#ifndef CAMERA_H
#define CAMERA_H

#include<d3dx9.h>

class Camera{
public:
	Camera(D3DXVECTOR3& pos, D3DXVECTOR3& lookatpos);
	~Camera();
	void Update();
private:
	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3 m_LookatPos;
};
#endif