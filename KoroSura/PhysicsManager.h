#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include<d3dx9.h>

//�n�ʂ̑���
class PhysicsManager{
public:
	static PhysicsManager& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new PhysicsManager;
		}

		return *m_pInstance;
	}

	//�����F �����_����J�����̍��W������������
	void SetCameraVec(const D3DXVECTOR3& cameraVec)
	{
		m_CameraVec = cameraVec;
		D3DXVec3Normalize(&m_CameraVec, &m_CameraVec);
	}

	float GetGravity() {return kGravity;}

	float GetDynamicCoefficientOfFriction() {return kDynamicCoefficientOfFriction;}

	float GetStaticCoefficientOfFriction() {return kStaticCoefficientOfFriction;}

	float* GetSlopeDeg() {return m_SlopeDeg;}

	const D3DXVECTOR3& GetNormalVector() {return m_NormalVector;}

	//���͂ŕ��ʂ��X���A�@�����X�V
	void Update();

private:
	PhysicsManager();
	~PhysicsManager();

	const float kSlopingDeg;
	const float kGravity;
	const float kDynamicCoefficientOfFriction;//�����C�W��
	const float kStaticCoefficientOfFriction;//�Î~���C�W��

	static PhysicsManager* m_pInstance;
	D3DXVECTOR3 m_NormalVector;
	D3DXVECTOR3 m_CameraVec;//�J�����̌����Ă������
	float m_SlopeDeg[2];
};
#endif