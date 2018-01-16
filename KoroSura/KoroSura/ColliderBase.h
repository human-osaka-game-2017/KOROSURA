#ifndef COLLIDER_H
#define COLLIDER_H

#include<d3dx9.h>
#include<string>
#include<functional>
#include<vector>

class ColliderBase {
public:
	ColliderBase(const std::string className, const D3DXVECTOR3& pos, std::function<void()> function);
	virtual ~ColliderBase();

	void SetPos(const D3DXVECTOR3& pos);
	void SetCollidedClassName(const std::vector<std::string>& classNames);
	void Execute();
	const std::vector<std::string>& GetCollidedClassNames();
	const std::string& GetAffiliatedClassName();
	const D3DXVECTOR3& GetPos();

protected:
	D3DXVECTOR3 m_Pos;
	const std::string m_ClassName;
	std::function<void()> m_Function;
	std::vector<std::string> m_CollidedClassNames;
};
#endif