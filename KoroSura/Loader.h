/**
 * @file	Loader.h
 * @brief	Loaderクラスのヘッダ
 * @author	shiraishi
 */
#ifndef LOADER_H
#define LOADER_H

#include<Windows.h>
#include<d3dx9.h>
#include<string>
#include"StageInfo.h"

class Loader{
public:
	Loader();
	~Loader();

	static DWORD WINAPI Load(LPVOID lpParameter);

private:
	void WINAPI ExecThread();

	void LoadMap(StageInfo::StageData* pStageData, std::string iniFileName, std::string csvFileName);
	void LoadEnemy(StageInfo::StageData* pStageData, std::string iniFileName);
	void LoadGimmick(StageInfo::StageData* pStageData, std::string iniFileName);
	void LoadSlime(StageInfo::StageData* pStageData, std::string iniFileName);
};
#endif