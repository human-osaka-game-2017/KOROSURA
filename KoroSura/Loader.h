/**
 * @file	Loader.h
 * @brief	Loaderクラスのヘッダ
 * @author	shiraishi
 */
#ifndef LOADER_H
#define LOADER_H

#include<Windows.h>

class Loader{
public:
	Loader();
	~Loader();

	static DWORD WINAPI Load(LPVOID lpParameter);

private:
	void WINAPI ExecThread();
};
#endif