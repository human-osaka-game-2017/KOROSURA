#ifndef SELECTION_H
#define SELECTION_H

#include<functional>
#include"ObjectBase.h"

class Selection :public ObjectBase {
public:
	Selection(int MaxChoices, std::function<void(int selectPoint)> function);
	virtual ~Selection();

	int GetCurrentSelection() {
		return m_SelectPoint;
	}

	virtual void Update();
	virtual void Draw() {};

private:
	//����L�[�������ꂽ��Ă΂��
	std::function<void(int selectPoint)> m_Function;
	int m_SelectPoint = 0;

	const int m_MaxChoices = 0;
};
#endif