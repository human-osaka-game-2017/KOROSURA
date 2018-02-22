#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include<d3dx9.h>

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

	//���͂ŕ��ʂ��X���A�@�����X�V
	void Update();

private:
	PhysicsManager();
	~PhysicsManager();

	void CalNormalVec();

	const float kSlopingDeg;
	const float kGravity;
	const float kDynamicCoefficientOfFriction;//�����C�W��
	const float kStaticCoefficientOfFriction;//�Î~���C�W��

	static PhysicsManager* m_pInstance;
	D3DXVECTOR3 m_Slope[2];	//!�X�������x�N�g��(���ʏ��x,z����)
	D3DXVECTOR3 m_NormalVector;//�@��
	D3DXVECTOR3 m_CameraVec;//�J�����̌����Ă������
};
#endif