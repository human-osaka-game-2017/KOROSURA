#include"StageInfo.h"
#include<Windows.h>
#include<string>

StageInfo::StageInfo()
{
	fileName = "Property\\StageLock.ini";
	Load();
}

StageInfo::~StageInfo()
{
	Save();
}

void StageInfo::UnLock()
{

}

void StageInfo::Load()
{
	char buff[256];

	ZeroMemory(buff, sizeof(buff));
	GetPrivateProfileString("Locking", "Stage01", "", buff, sizeof(buff), fileName);
}

void StageInfo::Save()
{

}