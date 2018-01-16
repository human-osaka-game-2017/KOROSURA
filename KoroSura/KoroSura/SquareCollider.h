#ifndef SQUARECOLLIDER_H
#define SQUARECOLLIDER_H

#include"ColliderBase.h"

class SquareCollider :public ColliderBase {
public:
	struct Size {
		float width;
		float height;
	};

	SquareCollider(const std::string className, const D3DXVECTOR3& pos, std::function<void()> function, const Size& size);
	virtual ~SquareCollider();

	const Size& GetSize();
private:
	Size m_Size;
};
#endif