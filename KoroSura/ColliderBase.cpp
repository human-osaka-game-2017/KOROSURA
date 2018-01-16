#include"ColliderBase.h"

ColliderBase::ColliderBase(const std::string className, const D3DXVECTOR3& pos, std::function<void()> function) :
	m_ClassName(className),
	m_Pos(pos),
	m_Function(function)
{

}

ColliderBase::~ColliderBase() {

}

void ColliderBase::Execute() {
	m_Function();
}

void ColliderBase::SetCollidedClassName(const std::vector<std::string>& classNames) {
	m_CollidedClassNames = classNames;
}

const D3DXVECTOR3& ColliderBase::GetPos() {
	return m_Pos;
}

void ColliderBase::SetPos(const D3DXVECTOR3& pos) {
	m_Pos = pos;
}

const std::string& ColliderBase::GetAffiliatedClassName() {
	return m_ClassName;
}

const std::vector<std::string>& ColliderBase::GetCollidedClassNames() {
	return m_CollidedClassNames;
}