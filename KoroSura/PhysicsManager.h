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

	D3DXVECTOR3* TranceformOnBoard(const D3DXVECTOR3& in,D3DXVECTOR3* out);

	//引数： 注視点からカメラの座標を引いたもの
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

	//傾きがあるかどうか
	bool CanRoll()
	{
		if (m_NormalVector.z == 0.0) {
			return false;
		}
		return true;
	}

	//入力で平面を傾け、法線を更新
	void Update();

	void Initialize();

private:
	PhysicsManager();
	~PhysicsManager();

	const float kSlopingDeg;
	const D3DXVECTOR3 kGravity;
	const float kDynamicCoefficientOfFriction;//動摩擦係数
	const float kStaticCoefficientOfFriction;//静止摩擦係数

	static PhysicsManager* m_pInstance;
	D3DXVECTOR3 m_NormalVector;
	D3DXVECTOR3 m_CameraVec;//カメラの向いている向き
	float m_SlopeDeg[2];
};
#endif