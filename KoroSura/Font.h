#ifndef FONT_H
#define FONT_H

#include<d3dx9.h>
#include<string>

#define DEFAULT_RECT 

class Font {
public:
	Font(std::string str);
	Font(float num);
	~Font();

	void ShowOutputWindow();
	void DrawInDisplay(const RECT& rect);
	void ShowWindowTitile();

	//bool GetShowOfInDisplayFlg();

private:
	LPD3DXFONT m_pFont = NULL;
	std::string m_Str;
	bool m_IsShowOfInDisplay = false;
	RECT m_Rect;

	void Create();
};
#endif