/**
 * @file	InitProperty.h
 * @brief	InitPropertyクラスのヘッダ
 * @author	shiraishi
 */
#ifndef INITPROPERTY_H
#define INITPROPERTY_H

#include"EnemyBase.h"
#include"GimmickBase.h"

 /**
  * @details	ゲーム中変わることのない値をiniファイルから取得し、保管するクラス
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
		float dynamicCoefficientOfFriction; //!	動摩擦係数
		float staticCoefficientOfFriction; //!	静止摩擦係数
		float deg; //マイフレーム傾ける角度 リネームする
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
	void LoadPhysics();//!物理的値の読み込み

	void LoadSpider();

	void LoadFence();

	static InitProperty* m_pInstance;

	InitialData m_InitialData;
};
#endif