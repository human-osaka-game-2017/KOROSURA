/**
 * @file	StageInfo.h
 * @brief	StageInfoクラスのヘッダ
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
  * @brief		StageInfoクラス(シングルトン)
  * @details	StageSelectSceneクラスからステージ番号を受け取り、Loaderに渡すクラス。ステージがロックされているかどうかも管理する
  */
class StageInfo{
public:
	/**
	 * @brief	インスタンスを返す関数
	 * @return	StageInfo&	StageInfoクラスのインスタンス
	 */
	StageInfo& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new StageInfo;
		}

		return *m_pInstance;
	}

	/**
	 * @brief		現在のステージ番号を取得
	 * @return int	現在のステージ番号が立っているビット
	 */
	int GetStageBits()
	{
		return m_CurrentStageBits;
	}

	/**
	 * @brief		現在のステージ番号を設定
	 * @param[in]	CurrentStageNum	設定したいステージ番号のビット
	 */
	void SetStageBits(int CurrentStageBits)
	{
		m_CurrentStageBits = CurrentStageBits;
	}

	/**
	 * @brief		どのステージUnLockされているか取得
	 * @return		int	UnLockされていたら立っているビット
	 */
	int GetStageUnLockBits()
	{
		return m_StageUnLockBits;
	}

	/**
	 * @brief	次のステージをアンロックする関数
	 * @details	ステージをクリアしたら呼ぶ。Save関数も自動で呼ぶ
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