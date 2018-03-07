#ifndef FONTUI_H
#define FONTUI_H

#include"UIBase.h"
#include"Utility.h"

class FontUI : public UIBase{
public:
	FontUI(D3DXVECTOR2 pos, D3DXVECTOR2 size);
	virtual ~FontUI();
	virtual void Update();
	virtual void Draw();

private:
	static bool m_isLoaded;
	static const int m_AsciiCodeSpace;
	static const float m_CharTu;

	char* m_OutputString;
	Utility::CUSTOMVERTEX m_Vertex[4];
};

#endif
