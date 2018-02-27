#include <math.h>
#include"Camera.h"
#include"Lib.h"
#include"Common.h"
#include"Renderer.h"
#include"Slime.h"
#include"DirectInput.h"

const float Camera::m_distance = 800.f;

Camera::Camera(D3DXVECTOR3& pos, D3DXVECTOR3* lookatpos) : m_Pos(pos),m_LookatPos(lookatpos)
{
	m_MovementMouse.x = 0.f;
	m_MovementMouse.y = 0.f;
	m_MovementMouse.z = 0.f;
}

Camera::~Camera()
{
}

void Camera::Update()
{
	DirectInput::GetInstance().GetMouseData();
	D3DXVECTOR3 stateMouse;
	stateMouse = DirectInput::GetInstance().GetMouseData()->Movement;
	D3DXVECTOR3 lookAtPos = *m_LookatPos;
	lookAtPos.y += 200.f;
	m_MovementMouse += stateMouse;
	m_MovementMouse.y = 1500.0f/*min(max(m_MovementMouse.y, 1000.f), 1500.f)*/;
	m_Pos.x = m_distance  * sin(m_MovementMouse.y * 0.0005f * D3DX_PI) 
						  * cos(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.x;
	//m_Pos.y = -m_distance * cos(m_MovementMouse.y * 0.0005f * D3DX_PI) + m_LookatPos->y;
	m_Pos.z = -m_distance * sin(m_MovementMouse.y * 0.0005f * D3DX_PI)
						  * sin(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.z;
	
	Lib::GetInstance().TransformView(m_Pos, lookAtPos, D3DXVECTOR3(0, 1, 0));
	Lib::GetInstance().TransformProjection(45.0f, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0f, 20000.0f);
}