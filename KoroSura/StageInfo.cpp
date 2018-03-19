#include<Windows.h>
#include<string>
#include"StageInfo.h"
#include"Common.h"

StageInfo* StageInfo::m_pInstance = nullptr;

StageInfo::StageInfo()
{
	Load();
}

StageInfo::~StageInfo()
{
	Save();
}

void StageInfo::UnLock()
{
	++m_UnLockingNum;
	Save();
}

void StageInfo::Load()
{
	m_UnLockingNum = GetPrivateProfileInt("Locking", "UnLockStage", 1, PROPERTY_FILENAME);
}

void StageInfo::Save()
{
	WritePrivateProfileString("Locking", "UnLockStage", std::to_string(m_UnLockingNum).c_str(), PROPERTY_FILENAME);
}
