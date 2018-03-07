#ifndef UIBASE_H
#define UIBASE_H

#include"ObjectBase.h"
#include <d3dx9.h>

class UIBase : public ObjectBase{
public:
	UIBase(D3DXVECTOR2 pos, D3DXVECTOR2 size);
	virtual ~UIBase();

	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	D3DXVECTOR2 m_Pos;
	D3DXVECTOR2 m_Size;
};


#endif