#include "Camera.h"
#include "Lib.h"
#include"Common.h"
#include"PhysicsManager.h"

Camera::Camera(D3DXVECTOR3& pos, D3DXVECTOR3& lookatpos) : m_Pos(pos),m_LookatPos(lookatpos)
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	Lib::GetInstance().TransformView(m_Pos, m_LookatPos, D3DXVECTOR3(0, 1, 0));
	Lib::GetInstance().TransformProjection(45.0f, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0f, 2000.0f);
	PhysicsManager::GetInstance().SetCameraVec(m_LookatPos - m_Pos);
}