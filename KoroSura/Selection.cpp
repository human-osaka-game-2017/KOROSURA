#include "Selection.h"
#include "Lib.h"

Selection::Selection(int MaxChoices, std::function<void(int selectPoint)> function):
	m_MaxChoices(MaxChoices),
	m_Function(function)
{
}

Selection::~Selection()
{
}

void Selection::Update()
{
	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::UP) == Utility::BUTTON_STATE::PUSH) {

		if (m_SelectPoint == m_MaxChoices - 1) {
			m_SelectPoint = 0;
		}
		else {
			++m_SelectPoint;
		}
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::DOWN) == Utility::BUTTON_STATE::PUSH) {

		if (m_SelectPoint == 0) {
			m_SelectPoint = m_MaxChoices - 1;
		}
		else {
			--m_SelectPoint;
		}
	}

	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::ENTER) == Utility::BUTTON_STATE::PUSH ||
		Lib::GetInstance().GetKeyState(Utility::KEY_KIND::SPACE) == Utility::BUTTON_STATE::PUSH) {

		m_Function(m_SelectPoint);
	}
}