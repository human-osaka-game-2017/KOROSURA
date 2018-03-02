/**
 * @file	StageInfo.h
 * @brief	StageInfo�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef STAGEINFO_H
#define STAGEINFO_H

#include<d3dx9.h>

 /**
  * @brief		StageInfo�N���X(�V���O���g��)
  * @details	StageSelectScene�N���X����X�e�[�W�ԍ����󂯎��ALoader�ɓn���N���X�B�X�e�[�W�����b�N����Ă��邩�ǂ������Ǘ�����
  */
class StageInfo{
public:
	struct MaterialData {
		D3DXVECTOR3 pos;
		float	angle;
		int		level;
		int		kind;
		bool	isBoss = false;
	};

	struct StageData {
		MaterialData	slimeData;
		MaterialData*	enemyData;
		MaterialData*	gimmickData;
		D3DXVECTOR3		mapSize;
		int		enemyNum;
		int		gimmickNum;
		int*	terrainData;
	};

	/**
	 * @brief	�C���X�^���X��Ԃ��֐�
	 * @return	StageInfo&	StageInfo�N���X�̃C���X�^���X
	 */
	static StageInfo& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new StageInfo;
		}

		return *m_pInstance;
	}

	/**
	 * @brief		���݂̃X�e�[�W�ԍ����擾
	 * @return int	���݂̃X�e�[�W�ԍ�(0�Ԏn�܂�)
	 */
	int GetCurrentStage()
	{
		return m_CurrentStage;
	}

	/**
	 * @brief		���݂̃X�e�[�W�ԍ���ݒ�
	 * @param[in]	CurrentStageNum	�ݒ肵�����X�e�[�W�ԍ�(�O�`�V)
	 */
	void SetSelectStage(int selectStage)
	{
		m_CurrentStage = selectStage;
	}

	/**
	 * @brief		���݂ǂ̃X�e�[�W�܂ŃA�����b�N����Ă��邩���擾
	 * @return		int	UnLock����Ă���ő�X�e�[�W�ԍ�
	 */
	int GetUnLockingStage()
	{
		return m_UnLockingNum;
	}

	/**
	 * @brief	���̃X�e�[�W���A�����b�N����֐�
	 * @details	�X�e�[�W���N���A������ĂԁBSave�֐��������ŌĂ�
	 */
	void UnLock();

	void SetStageData(const StageData& stageData) 
	{
		m_StageData = stageData;
	}

	StageData* GetStageData()
	{
		return &m_StageData;
	}

	void DeleteStageData()
	{
		delete[] m_StageData.enemyData;
		delete[] m_StageData.gimmickData;
		delete[] m_StageData.terrainData;
	}

	static const int kStageMax = 8;

private:
	StageInfo();
	~StageInfo();

	void Load();
	void Save();

	static StageInfo* m_pInstance;
	StageData m_StageData;
	int m_CurrentStage = 1;
	int m_UnLockingNum = 1;
};
#endif