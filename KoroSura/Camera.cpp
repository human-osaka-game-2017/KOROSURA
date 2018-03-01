#include <math.h>
#include"Camera.h"
#include"Lib.h"
#include"Common.h"
#include"PhysicsManager.h"
#include"Renderer.h"
#include"Slime.h"
#include"DirectInput.h"
#include"InitProperty.h"

Camera::Camera(D3DXVECTOR3* lookatpos) : 
	m_Pos(D3DXVECTOR3(0.0f, InitProperty::GetInstance().GetInitialData().cameraYPos,0.0f)),
	m_pLookatPos(lookatpos),
	m_MovementMouse(D3DXVECTOR3(0.0f,0.0f,0.0f)),
	kDistance(InitProperty::GetInstance().GetInitialData().cameraDistance),
	kLookAtPosYOffset(InitProperty::GetInstance().GetInitialData().lookAtPosYOffset)
{
	DirectInput::GetInstance().GetMouseData();
	D3DXVECTOR3 stateMouse;
	stateMouse = DirectInput::GetInstance().GetMouseData()->Movement;
	D3DXVECTOR3 lookAtPos = *m_pLookatPos;
	lookAtPos.y += kLookAtPosYOffset;
	m_MovementMouse += stateMouse;
	m_MovementMouse.y = 1500.0f/*min(max(m_MovementMouse.y, 1000.f), 1500.f)*/;
	m_Pos.x = kDistance  * sin(m_MovementMouse.y * 0.0005f * D3DX_PI)
		* cos(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.x;
	//m_Pos.y = -m_distance * cos(m_MovementMouse.y * 0.0005f * D3DX_PI) + m_LookatPos->y;
	m_Pos.z = -kDistance * sin(m_MovementMouse.y * 0.0005f * D3DX_PI)
		* sin(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.z;
	m_Pos.x = kDistance  * sin(m_MovementMouse.y * 0.0005f * D3DX_PI)
		* cos(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.x;
	//m_Pos.y = -m_distance * cos(m_MovementMouse.y * 0.0005f * D3DX_PI) + m_LookatPos->y;
	m_Pos.z = -kDistance * sin(m_MovementMouse.y * 0.0005f * D3DX_PI)
		* sin(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.z;
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//DirectInput::GetInstance().GetMouseData();
	//D3DXVECTOR3 stateMouse;
	//stateMouse = DirectInput::GetInstance().GetMouseData()->Movement;
	//D3DXVECTOR3 lookAtPos = *m_pLookatPos;
	//lookAtPos.y += kLookAtPosYOffset;
	//m_MovementMouse += stateMouse;
	//m_MovementMouse.y = 1500.0f/*min(max(m_MovementMouse.y, 1000.f), 1500.f)*/;
	//m_Pos.x = kDistance  * sin(m_MovementMouse.y * 0.0005f * D3DX_PI)
	//					  * cos(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.x;
	////m_Pos.y = -m_distance * cos(m_MovementMouse.y * 0.0005f * D3DX_PI) + m_LookatPos->y;
	//m_Pos.z = -kDistance * sin(m_MovementMouse.y * 0.0005f * D3DX_PI)
	//					  * sin(m_MovementMouse.x * 0.0005f * D3DX_PI) + lookAtPos.z;
	
	//Lib::GetInstance().TransformView(m_Pos, lookAtPos, D3DXVECTOR3(0, 1, 0));
	Lib::GetInstance().TransformView(D3DXVECTOR3(0.0f,200.0f,-1000), D3DXVECTOR3(10,550,10), D3DXVECTOR3(0, 1, 0));
	PhysicsManager::GetInstance().SetCameraVec(D3DXVECTOR3(10, 550, 10) - m_Pos);
	//Lib::GetInstance().TransformProjection(45.0f, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0f, 20000.0f);

	//PhysicsManager::GetInstance().SetCameraVec(lookAtPos - m_Pos);
}