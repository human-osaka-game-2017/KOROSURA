#include"Loader.h"

Loader::Loader()
{
}

Loader::~Loader()
{
}

DWORD WINAPI Loader::Load(LPVOID lpParameter)
{
	Sleep(5000);
	OutputDebugString("LOAD’†\n");
	static_cast<Loader*>(lpParameter)->ExecThread();
	return S_OK;
}

void WINAPI Loader::ExecThread()
{
}