#ifndef GAMECLEAR_H
#define GAMECLEAR_H

#include<d3dx9.h>
#include"ObjectBase.h"

class GameClear : public ObjectBase
{
public:
	GameClear();
	virtual~GameClear();

	virtual void Update();
	virtual void Draw();
	void StartMusic();
	void EndMusic();
private:
	const int kPngWidth = 8192;
	const int kPngHeight = 1024;

	const D3DXVECTOR2 kStageClearPos = D3DXVECTOR2(800.0f, 200.0f);
	const D3DXVECTOR2 kStageNextPos = D3DXVECTOR2(800.0f, 520.0f);
	const D3DXVECTOR2 kStageSelectPos = D3DXVECTOR2(800.0f, 770.0f);
	const int kStageClearWidth = 650;
	const int kStageClearHeight = 175;
	const int kStageNextWidth = 500;
	const int kStageNextHeight = 150;
	const int kStageSelectWidth = 500;
	const int kStageSelectHeight = 150;
};

#endif 


