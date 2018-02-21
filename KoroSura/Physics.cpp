#include"Physics.h"
#include"PhysicsManager.h"

Physics::Physics()
{

}

Physics::~Physics()
{
}

D3DXVECTOR3* Physics::GetFallVec(D3DXVECTOR3* fallVec, const D3DXVECTOR3& currentPos)
{
	//�@��
	D3DXVECTOR3 normalVec = PhysicsManager::GetInstance().GetNormalVector();

	//�n�ʂ�X�������x�N�g��
	D3DXVECTOR3 groundVecX = PhysicsManager::GetInstance().GetSlope()[0];

	//���݂̃I�u�W�F�N�g���W�𕽖ʏ�ɓ��e�������W
	D3DXVECTOR3 pos = currentPos;
	pos.y = (normalVec.x*(groundVecX.x - currentPos.x)) / normalVec.y + groundVecX.y + (normalVec.z*(groundVecX.z - currentPos.z)) / normalVec.y;

	//���ʂ�x-z���ʂ̌������钼����
	//currentPos��ʂ遪�̒����̐���
	//�̌���������W
	D3DXVECTOR3 crossPos;
	crossPos.x = (pow(normalVec.z, 2)*pos.x + normalVec.z*(normalVec.z*groundVecX.x + normalVec.y*groundVecX.y + normalVec.z*groundVecX.z - normalVec.z*pos.z)) /
		(pow(normalVec.z, 2) + pow(normalVec.x, 2));
	crossPos.y = 0.0f;
	crossPos.z = pow(normalVec.z, 3)*pos.x + normalVec.x*normalVec.z*(normalVec.z*groundVecX.x + normalVec.y*groundVecX.y + normalVec.z*groundVecX.z - normalVec.z*pos.z) /
		(normalVec.x*(pow(normalVec.z, 2) + pow(normalVec.x, 2))) + pos.z - (pos.x*normalVec.z) / normalVec.x;

	if (pos.y < 0) {
		*fallVec = pos - crossPos;
	}
	else {
		*fallVec = crossPos - pos;
	}

	//���K��
	D3DXVec3Normalize(fallVec, fallVec);

	return fallVec;
}
