#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "SceneBase.h"
#include <d3dx9.h>

class MainScene :public SceneBase{
public:
	MainScene();
	virtual ~MainScene();

	//•Û‚µ‚Ä‚¢‚éObujectBase‚ÌUpdateŠÖ”‚ğ‚æ‚ñ‚Å‚¢‚Ü‚·
	virtual SceneBase::SCENE_ID Update();
	virtual void Draw();

private:
	D3DXHANDLE m_View;
	D3DXHANDLE m_Proj;
	D3DXHANDLE m_Light;
};
#endif