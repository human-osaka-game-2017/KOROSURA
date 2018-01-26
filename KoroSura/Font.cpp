#include"Font.h"
#include"DirectGraphics.h"
#include<tchar.h>

Font::Font(std::string str) {
	m_Str = str;

	Create();
}

Font::Font(float num) {
	m_Str = std::to_string(num);

	Create();
}

void Font::Create() {
	D3DXCreateFont(
		*DirectGraphics::GetInstance().GetDevice(),
		20,
		10,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		"‚l‚r ƒSƒVƒbƒN",
		&m_pFont
	);
}

Font::~Font() {
	SAFE_RELEASE(m_pFont);
}

void Font::DrawInDisplay(const RECT& rect) {
	//m_IsShowOfInDisplay = true;
	RECT tmpRect = rect;
	m_pFont->DrawTextA(NULL, m_Str.c_str(), m_Str.size(), &tmpRect, DT_CENTER, 0xFF88FF88);
}

//void Font::DrawInDisplay() {
//	m_pFont->DrawTextA(NULL, m_Str.c_str(), m_Str.size(), &m_Rect, DT_CENTER, 0x00000000);
//}

void Font::ShowOutputWindow() {
	OutputDebugString(m_Str.c_str());
}

void Font::ShowWindowTitile() {
	SetWindowText(DirectGraphics::GetInstance().GethWnd(), m_Str.c_str());
}