/**
 * @file	Loader.h
 * @brief	Loader�N���X�̃w�b�_
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