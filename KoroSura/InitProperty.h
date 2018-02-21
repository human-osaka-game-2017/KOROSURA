/**
 * @file	InitProperty.h
 * @brief	InitProperty�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef INITPROPERTY_H
#define INITPROPERTY_H

#include"EnemyBase.h"
#include"GimmickBase.h"

 /**
  * @details	�Q�[�����ς�邱�Ƃ̂Ȃ��l��ini�t�@�C������擾���A�ۊǂ���N���X
  */
class InitProperty{
public:
	static InitProperty& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new InitProperty;
		}
		return *m_pInstance;
	}

	struct SlimeInitialData {
		D3DXVECTOR3	colliderOffset;
		float radius;
		float modelOffset;
	};

	struct MaterialInitialData {
		D3DXVECTOR3 colliderOffset;
		D3DXVECTOR3 colliderSize;
		float modelOffset;
	};

	struct InitialData {
		SlimeInitialData	slimeInitialData;
		MaterialInitialData	enemyInitialData[static_cast<int>(EnemyBase::ENEMY_KIND::MAX)];
		MaterialInitialData	gimmickInitialData[static_cast<int>(GimmickBase::GIMMICK_KIND::MAX)];
		float gravity;
		float dynamicCoefficientOfFriction; //!	�����C�W��
		float staticCoefficientOfFriction; //!	�Î~���C�W��
		float deg; //�}�C�t���[���X����p�x ���l�[������
	};

	const InitialData& GetInitialData() {
		return m_InitialData;
	}

private:
	InitProperty();
	~InitProperty();

	void LoadSlime();
	void LoadEnemy();
	void LoadGimmick();
	void LoadPhysics();//!�����I�l�̓ǂݍ���

	void LoadSpider();

	void LoadFence();

	static InitProperty* m_pInstance;

	InitialData m_InitialData;
};
#endif