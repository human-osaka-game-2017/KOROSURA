#include"Loader.h"
#include<string>
#include"Common.h"
#include"ModelManager.h"

Loader::Loader()
{
}

Loader::~Loader()
{
}

DWORD WINAPI Loader::Load(LPVOID lpParameter)
{
	static_cast<Loader*>(lpParameter)->ExecThread();
	return S_OK;
}

void WINAPI Loader::ExecThread()
{
	StageInfo::StageData stageData;

	std::string tmp = "Property\\Stage";
	std::string csvFileName = tmp + std::to_string(StageInfo::GetInstance().GetCurrentStage() + 1) + ".csv";
	std::string iniFileName = tmp + std::to_string(StageInfo::GetInstance().GetCurrentStage() + 1) + ".ini";

	LoadMap(&stageData, iniFileName, csvFileName);
	LoadEnemy(&stageData, iniFileName);
	LoadGimmick(&stageData, iniFileName);
	LoadSlime(&stageData, iniFileName);

	StageInfo::GetInstance().SetStageData(stageData);

	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\board.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\Cerberus_og2.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\fence.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\goblin.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\goblin_p.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\minotaur.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\mushroom_b.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\mushroom_p.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\mushroom_r.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\sky.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\slime.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\treant_mg.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\treant_mp.fbx");
	ModelManager::GetInstance().LoadFBXFile("FBX\\FBXModel\\treant_my.fbx");

	m_WasComplete = true;
	OutputDebugString("load終了");
}

void Loader::LoadMap(StageInfo::StageData* pStageData, std::string iniFileName, std::string csvFileName)
{
	pStageData->mapSize.x =
		GetPrivateProfileInt("Size", "X", 1, iniFileName.c_str());

	pStageData->mapSize.z=
		GetPrivateProfileInt("Size", "Z", 1, iniFileName.c_str());

	pStageData->terrainData = new int[pStageData->mapSize.x*pStageData->mapSize.z];

	//csv読み込み
	FILE* pFile;

	fopen_s(&pFile, csvFileName.c_str(), "r");
	for (int i = 0; i < pStageData->mapSize.x; i++)
	{
		for (int j = 0; j < pStageData->mapSize.z; j++)
		{
			//ポインタずらしてます
			fscanf_s(pFile, "%d,", (pStageData->terrainData + static_cast<int>(j + i*pStageData->mapSize.x)));
		}
	}
	fclose(pFile);
}

void Loader::LoadEnemy(StageInfo::StageData* pStageData, std::string iniFileName)
{
	pStageData->enemyNum =
		GetPrivateProfileInt("Size", "Enemy数", 0, iniFileName.c_str());

	pStageData->enemyData = new StageInfo::MaterialData[pStageData->enemyNum];

	for (int i = 1; i < pStageData->enemyNum; ++i) {
		std::string tagName = "Enemy";
		tagName += std::to_string(i);

		pStageData->enemyData[i - 1].kind =
			GetPrivateProfileInt(tagName.c_str(), "Kind", 0, iniFileName.c_str());

		pStageData->enemyData[i - 1].pos.x =
			GetPrivateProfileInt(tagName.c_str(), "X", 0, iniFileName.c_str());

		pStageData->enemyData[i - 1].pos.y =
			GetPrivateProfileInt(tagName.c_str(), "Y", 0, iniFileName.c_str());

		pStageData->enemyData[i - 1].pos.z =
			GetPrivateProfileInt(tagName.c_str(), "Z", 0, iniFileName.c_str());

		pStageData->enemyData[i - 1].level =
			GetPrivateProfileInt(tagName.c_str(), "Level", 1, iniFileName.c_str());

		pStageData->enemyData[i - 1].angle =
			GetPrivateProfileInt(tagName.c_str(), "Angle", 0, iniFileName.c_str());
	}
}

void Loader::LoadGimmick(StageInfo::StageData* pStageData, std::string iniFileName)
{
	pStageData->gimmickNum =
		GetPrivateProfileInt("Size", "Gimmick数", 0, iniFileName.c_str());

	pStageData->gimmickData = new StageInfo::MaterialData[pStageData->gimmickNum];

	for (int i = 1; i <= pStageData->gimmickNum; ++i) {
		std::string tagName = "Enemy";
		tagName += std::to_string(i);

		pStageData->gimmickData[i - 1].kind =
			GetPrivateProfileInt(tagName.c_str(), "Kind", 0, iniFileName.c_str());

		pStageData->gimmickData[i - 1].pos.x =
			GetPrivateProfileInt(tagName.c_str(), "X", 0, iniFileName.c_str());

		pStageData->gimmickData[i - 1].pos.y =
			GetPrivateProfileInt(tagName.c_str(), "Y", 0, iniFileName.c_str());

		pStageData->gimmickData[i - 1].pos.z =
			GetPrivateProfileInt(tagName.c_str(), "Z", 0, iniFileName.c_str());

		pStageData->gimmickData[i - 1].angle =
			GetPrivateProfileInt(tagName.c_str(), "Angle", 0, iniFileName.c_str());
	}
}

void Loader::LoadSlime(StageInfo::StageData* pStageData, std::string iniFileName)
{
	pStageData->slimeData.pos.x =
		GetPrivateProfileInt("Slime", "X", 0, iniFileName.c_str());

	pStageData->slimeData.pos.y =
		GetPrivateProfileInt("Slime", "Y", 0, iniFileName.c_str());

	pStageData->slimeData.pos.z =
		GetPrivateProfileInt("Slime", "Z", 0, iniFileName.c_str());

	pStageData->slimeData.level =
		GetPrivateProfileInt("Slime", "Level", 1, iniFileName.c_str());

	pStageData->slimeData.angle =
		GetPrivateProfileInt("Slime", "Angle", 0, iniFileName.c_str());
}