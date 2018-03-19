#ifndef SELECTION_H
#define SELECTION_H

#include<functional>

class Selecter{
public:
	Selecter(int MaxChoices, std::function<void(int selectPoint)> function);
	~Selecter();

	//0`‚Ì”Ô†
	int GetCurrentSelection() {
		return m_SelectPoint;
	}

	void Update();

private:
	//Œˆ’èƒL[‚ª‰Ÿ‚³‚ê‚½‚çŒÄ‚Î‚ê‚é
	std::function<void(int selectPoint)> m_Function;
	int m_SelectPoint = 0;

	const int m_MaxChoices = 0;
};
#endif