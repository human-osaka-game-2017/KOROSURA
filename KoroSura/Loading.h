#ifndef LOADING_H
#define LOADING_H

#include"SceneBase.h"

class Loading :public SceneBase{
public:
	Loading();
	virtual ~Loading();

	virtual SCENE_ID Update();
	virtual void Draw();
};

#endif