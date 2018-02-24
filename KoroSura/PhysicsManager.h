#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include<d3dx9.h>

//地面の操作
class PhysicsManager{
public:
	static PhysicsManager& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new PhysicsManager;
		}

		return *m_pInstance;
	}

	void SetCameraVec(const D3DXVECTOR3& cameraVec)
	{
		m_CameraVec = cameraVec;
	}

	const D3DXVECTOR3& GetNormalVector()
	{
		return m_NormalVector;
	}

	const D3DXVECTOR3* GetSlope()
	{
		return m_Slope;
	}

	float GetGravity() 
	{
		return kGravity;
	}

	float GetDynamicCoefficientOfFriction()
	{
		return kDynamicCoefficientOfFriction;
	}

	float GetStaticCoefficientOfFriction()
	{
		return kStaticCoefficientOfFriction;
	}

	//入力で平面を傾け、法線を更新
	void Update();

private:
	PhysicsManager();
	~PhysicsManager();

	void CalNormalVec();

	const float kSlopingDeg;
	const float kGravity;
	const float kDynamicCoefficientOfFriction;//動摩擦係数
	const float kStaticCoefficientOfFriction;//静止摩擦係数

	static PhysicsManager* m_pInstance;
	D3DXVECTOR3 m_Slope[2];	//!傾き方向ベクトル(平面上のx,z方向)
	D3DXVECTOR3 m_NormalVector;//法線
	D3DXVECTOR3 m_CameraVec;//カメラの向いている向き
};
#endif