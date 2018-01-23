/**
 * @file	StageInfo.h
 * @brief	StageInfo�N���X�̃w�b�_
 * @author	shiraishi
 */
#ifndef STAGEINFO_H
#define STAGEINFO_H

#define STAGE_1		0x80000000
#define STAGE_2		0x40000000
#define STAGE_3		0x20000000
#define STAGE_4		0x10000000
#define STAGE_5		0x08000000
#define STAGE_6		0x04000000
#define STAGE_7		0x02000000
#define STAGE_8		0x01000000

 /**
  * @brief		StageInfo�N���X(�V���O���g��)
  * @details	StageSelectScene�N���X����X�e�[�W�ԍ����󂯎��ALoader�ɓn���N���X�B�X�e�[�W�����b�N����Ă��邩�ǂ������Ǘ�����
  */
class StageInfo{
public:
	/**
	 * @brief	�C���X�^���X��Ԃ��֐�
	 * @return	StageInfo&	StageInfo�N���X�̃C���X�^���X
	 */
	StageInfo& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new StageInfo;
		}

		return *m_pInstance;
	}

	/**
	 * @brief		���݂̃X�e�[�W�ԍ����擾
	 * @return int	���݂̃X�e�[�W�ԍ��������Ă���r�b�g
	 */
	int GetStageBits()
	{
		return m_CurrentStageBits;
	}

	/**
	 * @brief		���݂̃X�e�[�W�ԍ���ݒ�
	 * @param[in]	CurrentStageNum	�ݒ肵�����X�e�[�W�ԍ��̃r�b�g
	 */
	void SetStageBits(int CurrentStageBits)
	{
		m_CurrentStageBits = CurrentStageBits;
	}

	/**
	 * @brief		�ǂ̃X�e�[�WUnLock����Ă��邩�擾
	 * @return		int	UnLock����Ă����痧���Ă���r�b�g
	 */
	int GetStageUnLockBits()
	{
		return m_StageUnLockBits;
	}

	/**
	 * @brief	���̃X�e�[�W���A�����b�N����֐�
	 * @details	�X�e�[�W���N���A������ĂԁBSave�֐��������ŌĂ�
	 */
	void UnLock();

private:
	StageInfo();
	~StageInfo();

	void Load();
	void Save();

	StageInfo* m_pInstance;
	int m_CurrentStageBits = STAGE_1;
	int m_StageUnLockBits;
};
#endif