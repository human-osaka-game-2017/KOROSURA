#ifndef SELECTION_H
#define SELECTION_H

#include<functional>

class Selecter{
public:
	Selecter(int MaxChoices, std::function<void(int selectPoint)> function);
	~Selecter();

	//0�`�̔ԍ�
	int GetCurrentSelection() {
		return m_SelectPoint;
	}

	void Update();

private:
	//����L�[�������ꂽ��Ă΂��
	std::function<void(int selectPoint)> m_Function;
	int m_SelectPoint = 0;

	const int m_MaxChoices = 0;
};
#endif