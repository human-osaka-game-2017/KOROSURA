#ifndef GAMEOVER_H
#define GAMEOVER_H

#include<d3dx9.h>
#include "ObjectBase.h"

class GameOver : public ObjectBase
{
public:
	GameOver();
	virtual ~GameOver();

	virtual void Update();
	virtual void Draw();
private:
	const int kPngWidth = 8192;
	const int kPngHeight = 1024;

	const D3DXVECTOR2 kStageOverPos = D3DXVECTOR2(800.0f, 200.0f);
	const D3DXVECTOR2 kStageRetryPos = D3DXVECTOR2(800.0f, 520.0f);
	const D3DXVECTOR2 kStageSelectPos = D3DXVECTOR2(800.0f, 770.0f);
	const int kStageOverWidth = 650;
	const int kStageOverHeight = 175;
	const int kStageRetryWidth = 500;
	const int kStageRetryHeight = 150;
	const int kStageSelectWidth = 500;
	const int kStageSelectHeight = 150;
};

#endif