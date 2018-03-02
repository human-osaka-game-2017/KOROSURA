#ifndef GAMEOVER_H
#define GAMEOVER_H

#include<d3dx9.h>
#include "ObjectBase.h"

class Selecter;

class GameOver : public ObjectBase
{
public:
	GameOver();
	virtual ~GameOver();

	bool GetRetryStage() { return m_RetryStage; }
	bool GetSelectStage() { return m_Select; }


	virtual void Update();
	virtual void Draw();
	void StartMusic();
	void EndMusic();
	void WasSelect();
private:
	bool m_RetryStage;
	bool m_Select;

	Selecter* m_pSelecter;

	int m_selectNum;

	const int kPngWidth = 8192;
	const int kPngHeight = 1024;
	const int kBackPngWidth = 1600;
	const int kBackPngHeight = 900;
	D3DXVECTOR2 kSlimePos = D3DXVECTOR2(450.0f, 520.0f);
	const D3DXVECTOR2 kStageOverPos = D3DXVECTOR2(800.0f, 200.0f);
	const D3DXVECTOR2 kStageRetryPos = D3DXVECTOR2(800.0f, 520.0f);
	const D3DXVECTOR2 kStageSelectPos = D3DXVECTOR2(800.0f, 770.0f);
	const int kSlimeWidth = 150;
	const int kSlimeHeight = 150;
	const int kStageOverWidth = 800;
	const int kStageOverHeight = 175;
	const int kStageRetryWidth = 500;
	const int kStageRetryHeight = 150;
	const int kStageSelectWidth = 500;
	const int kStageSelectHeight = 150;
};

#endif