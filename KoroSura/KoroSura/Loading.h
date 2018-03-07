#ifndef LOADING_H
#define LOADING_H

#include<Windows.h>
#include"SceneBase.h"

class Loader;
class NowLoadingLogo;

class Loading :public SceneBase{
public:
	Loading();
	virtual ~Loading();

	virtual SCENE_ID Update();
	virtual void Draw();

private:
	Loader* m_pLoader;
	NowLoadingLogo* m_pNowLoadingLogo;

	HANDLE m_hThread;
};
#endif