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

	D3DXVECTOR3* TranceformOnBoard(const D3DXVECTOR3& in,D3DXVECTOR3* out);

	//�����F �����_����J�����̍��W������������
	void SetCameraVec(const D3DXVECTOR3& cameraVec)
	{
		m_CameraVec = cameraVec;
		D3DXVec3Normalize(&m_CameraVec, &m_CameraVec);
	}

	const D3DXVECTOR3 GetGravity() {return kGravity;}

	float GetDynamicCoefficientOfFriction() {return kDynamicCoefficientOfFriction;}

	float GetStaticCoefficientOfFriction() {return kStaticCoefficientOfFriction;}

	const float* GetSlopeDeg() {return m_SlopeDeg;}

	const D3DXVECTOR3& GetNormalVector() {return m_NormalVector;}

	//�X�������邩�ǂ���
	bool CanRoll()
	{
		if (m_NormalVector.z == 0.0) {
			return false;
		}
		return true;
	}

	//���͂ŕ��ʂ��X���A�@�����X�V
	void Update();

	void Initialize();

private:
	PhysicsManager();
	~PhysicsManager();

	const float kSlopingDeg;
	const D3DXVECTOR3 kGravity;
	const float kDynamicCoefficientOfFriction;//�����C�W��
	const float kStaticCoefficientOfFriction;//�Î~���C�W��

	static PhysicsManager* m_pInstance;
	D3DXVECTOR3 m_NormalVector;
	D3DXVECTOR3 m_CameraVec;//�J�����̌����Ă������
	float m_SlopeDeg[2];
};
#endif