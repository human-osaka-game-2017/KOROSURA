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

	//“ü—Í‚Å•½–Ê‚ğŒX‚¯A–@ü‚ğXV
	void Update();

private:
	PhysicsManager();
	~PhysicsManager();

	void CalNormalVec();

	const float kSlopingDeg;
	const float kGravity;
	const float kDynamicCoefficientOfFriction;//“®–€CŒW”
	const float kStaticCoefficientOfFriction;//Ã~–€CŒW”

	static PhysicsManager* m_pInstance;
	D3DXVECTOR3 m_Slope[2];	//!ŒX‚«•ûŒüƒxƒNƒgƒ‹(•½–Êã‚Ìx,z•ûŒü)
	D3DXVECTOR3 m_NormalVector;//–@ü
	D3DXVECTOR3 m_CameraVec;//ƒJƒƒ‰‚ÌŒü‚¢‚Ä‚¢‚éŒü‚«
};
#endif