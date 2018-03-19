#include"Physics.h"
#include"PhysicsManager.h"

Physics::Physics()
{
}

Physics::~Physics()
{
}

D3DXVECTOR3* Physics::GetRollVec(D3DXVECTOR3* rollVec)
{
	//�@��
	D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

	//�d��
	D3DXVECTOR3 gravity = PhysicsManager::GetInstance().GetGravity();

	//����x�N�g�� S=L-(N * L)/(|N|^2)*N
	*rollVec = gravity - ((D3DXVec3Dot(&normalVec, &gravity)) / (pow(D3DXVec3Length(&normalVec), 2))) * normalVec;
	//*rollVec = normalVec + gravity;

	//���K��
	D3DXVec3Normalize(rollVec, rollVec);

	return rollVec;
}

D3DXVECTOR3* Physics::GetRollVec(D3DXVECTOR3* rollVec, const D3DXVECTOR3& currentPos)
{
	//�@��
	D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

	//���݂̃I�u�W�F�N�g���W�𕽖ʏ�ɓ��e�������W
	D3DXVECTOR3 pos = currentPos;
	pos.y = -((normalVec.x*pos.x + normalVec.z*pos.z) / pos.z);

	//���ʂ�x-z���ʂ̌������钼����
	//currentPos��ʂ遪�̒����̐���
	//�̌���������W
	D3DXVECTOR3 crossPos;
	crossPos.x = (pow(normalVec.z, 2)*pos.x - normalVec.x*normalVec.z*pos.z) /
		(pow(normalVec.x, 2) + pow(normalVec.z, 2));
	crossPos.y = 0.0f;
	crossPos.z = -(normalVec.x / normalVec.z)*(pow(normalVec.z, 2)*pos.x - normalVec.x*normalVec.z*pos.z) /
		(pow(normalVec.x, 2) + pow(normalVec.z, 2));

	if (pos.y < 0) {
		*rollVec = pos - crossPos;
	}
	else {
		*rollVec = crossPos - pos;
	}

	//���K��
	D3DXVec3Normalize(rollVec, rollVec);

	return rollVec;
}

float Physics::GetRollVelocity(bool isMoving)
{
	//���x�X�V
	float rad = 0.0f;
	{
		//�@��
		D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

		float tmp = acos(normalVec.y / D3DXVec3Length(&normalVec));
		if (tmp > D3DXToRadian(90.0f)) {
			tmp = D3DXToRadian(180.0f) - tmp;
		}
		rad = tmp;
	}

	if (isMoving) {
		//if sin�� < ��cos��
		if (sin(rad) < PhysicsManager::GetInstance().GetDynamicCoefficientOfFriction()*cos(rad)) {
			m_Velocity = 0;
		}
		else {
			//��Βl
			float gravity = fabs(PhysicsManager::GetInstance().GetGravity().y);
			m_Velocity = gravity*sin(rad) - PhysicsManager::GetInstance().GetDynamicCoefficientOfFriction()*gravity*cos(rad);
		}
	}
	else {
		//if sin�� < ��cos��
		if (sin(rad) < PhysicsManager::GetInstance().GetStaticCoefficientOfFriction()*cos(rad)) {
			m_Velocity = 0;
		}
		else {
			//��Βl
			float gravity = fabs(PhysicsManager::GetInstance().GetGravity().y);
			m_Velocity = gravity*sin(rad) - PhysicsManager::GetInstance().GetDynamicCoefficientOfFriction()*gravity*cos(rad);
		}
	}


	//m_Velocity = a;

	return m_Velocity;
}

//float Physics::GetYLength(const D3DXVECTOR3& currentPos)
//{
//	////�@��
//	//D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();
//
//	////�n�ʂ�x-z�̌X��
//	//float tmp = acos(normalVec.y / D3DXVec3Length(&normalVec));
//	//if (tmp > D3DXToRadian(90.0f)) {
//	//	tmp = D3DXToRadian(180.0f) - tmp;
//	//}
//	//float rad = tmp;
//
//	//static float preRad = 0.0f;
//
//	//float distanceRad = preRad - rad;
//
//	//preRad = rad;
//
//	////float ret = sqrt(pow(currentPos.x,2)+ pow(currentPos.z, 2)) * sin(rad)
//	////	+ currentPos.y * cos(rad);
//	//float ret = D3DXVec3Length(&currentPos)*sin(distanceRad);
//
//	//return ret;
//	return 0;
//}