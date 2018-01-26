#ifndef TEAMLOGO_H
#define TEAMLOGO_H

#include<functional>
#include "ObjectBase.h"
#include "Fader.h"

class TeamLogo :public ObjectBase{
public:
	TeamLogo(std::function<void()> function);
	virtual ~TeamLogo();

	virtual void Update();
	virtual void Draw();

private:
	int m_FrCnt = 0;
	bool m_ShouldDraw = true;
	//ï`âÊèIÇÌÇ¡ÇΩÇÁåƒÇŒÇÍÇÈ
	std::function<void()> m_Function;
	Fader* pFader = nullptr;

	const int kInterval = 240;
	const int kSize = 600;
};
#endif