/**
 * @file	StageInfo.h
 * @brief	StageInfoクラスのヘッダ
 * @author	shiraishi
 */
#ifndef STAGEINFO_H
#define STAGEINFO_H

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
	static StageInfo& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new StageInfo;
		}

		return *m_pInstance;
	}

	/**
	 * @brief		現在のステージ番号を取得
	 * @return int	現在のステージ番号
	 */
	int GetCurrentStage()
	{
		return m_CurrentStage;
	}

	/**
	 * @brief		現在のステージ番号を設定
	 * @param[in]	CurrentStageNum	設定したいステージ番号
	 */
	void SetSelectStage(int selectStage)
	{
		m_CurrentStage = selectStage;
	}

	/**
	 * @brief		現在どのステージまでアンロックされているかを取得
	 * @return		int	UnLockされている最大ステージ番号
	 */
	int GetUnLockingStage()
	{
		return m_UnLockingNum;
	}

	/**
	 * @brief	次のステージをアンロックする関数
	 * @details	ステージをクリアしたら呼ぶ。Save関数も自動で呼ぶ
	 */
	void UnLock();

	static const int kStageMax = 8;

private:
	StageInfo();
	~StageInfo();

	void Load();
	void Save();

	static StageInfo* m_pInstance;
	int m_CurrentStage = 1;
	int m_UnLockingNum = 1;
};
#endif