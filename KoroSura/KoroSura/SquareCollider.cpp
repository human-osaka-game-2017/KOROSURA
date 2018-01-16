#include"SquareCollider.h"

SquareCollider::SquareCollider(const std::string className, const D3DXVECTOR3& pos, std::function<void()> function, const Size& size) :
	ColliderBase(className, pos,function),
	m_Size(size)
{

}

SquareCollider::~SquareCollider() {

}

const SquareCollider::Size& SquareCollider::GetSize() {
	return m_Size;
}