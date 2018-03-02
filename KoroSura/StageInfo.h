/**
 * @file	StageInfo.h
 * @brief	StageInfoクラスのヘッダ
 * @author	shiraishi
 */
#ifndef STAGEINFO_H
#define STAGEINFO_H

#include<d3dx9.h>

 /**
  * @brief		StageInfoクラス(シングルトン)
  * @details	StageSelectSceneクラスからステージ番号を受け取り、Loaderに渡すクラス。ステージがロックされているかどうかも管理する
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
	 * @return int	現在のステージ番号(0番始まり)
	 */
	int GetCurrentStage()
	{
		return m_CurrentStage;
	}

	/**
	 * @brief		現在のステージ番号を設定
	 * @param[in]	CurrentStageNum	設定したいステージ番号(０～７)
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