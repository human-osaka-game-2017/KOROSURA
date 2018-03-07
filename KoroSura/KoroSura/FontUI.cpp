#include <string.h>
#include"FontUI.h"
#include"Lib.h"
#include"Renderer.h"
#include"DirectGraphics.h"


bool FontUI::m_isLoaded = false;

const int FontUI::m_AsciiCodeSpace = 32;
const float FontUI::m_CharTu = 1.0 / 95;

FontUI::FontUI(D3DXVECTOR2 pos, D3DXVECTOR2 size) : UIBase::UIBase(pos,size)
{
	for (int i = 0; i < 4; i++) {
		m_Vertex[i].x = 0.f;
		m_Vertex[i].y = 0.f;
		m_Vertex[i].z = 0.01f;
		m_Vertex[i].rhw = 1.f;
		m_Vertex[i].color = 0xffffffff;
		m_Vertex[i].tu = 0.f;
		m_Vertex[i].tv = 0.f;
	}
	m_Vertex[0].x = pos.x - size.x / 2;
	m_Vertex[1].x = pos.x + size.x / 2;
	m_Vertex[2].x = pos.x + size.x / 2;
	m_Vertex[3].x = pos.x - size.x / 2;

	m_Vertex[0].y = pos.y - size.y / 2;
	m_Vertex[1].y = pos.y - size.y / 2;
	m_Vertex[2].y = pos.y + size.y / 2;
	m_Vertex[3].y = pos.y + size.y / 2;

	m_Vertex[0].tv = 0.f;
	m_Vertex[1].tv = 0.f;
	m_Vertex[2].tv = 1.f;
	m_Vertex[3].tv = 1.f;
	m_OutputString = "Unknown";
	if (m_isLoaded != true) {
		Lib::GetInstance().LoadPictureFile("Picture\\Font.png", 950.f, 20.f);
		m_isLoaded = true;
	}
}


FontUI::~FontUI()
{
	if (m_isLoaded != false) {
		Lib::GetInstance().CancelTexture("Picture\\Font.png");
		m_isLoaded = false;
	}
}

void FontUI::Update()
{

}

void FontUI::Draw()
{
	Lib::GetInstance().SetRenderState2D();
	(*DirectGraphics::GetInstance().GetDevice())->SetFVF(D3DFVF_CUSTOMVERTEX);
	int StringCount = strlen(m_OutputString);
	for (int i = 0; i < StringCount; i++) {
		Utility::CUSTOMVERTEX vertex[4];
		for (int j = 0; j < 4; j++) {
			vertex[j] = m_Vertex[j];
			vertex[j].x += m_Size.x * i;
		}
		vertex[0].tu = (m_OutputString[i] - m_AsciiCodeSpace) * m_CharTu;
		vertex[1].tu = (m_OutputString[i] - m_AsciiCodeSpace) * m_CharTu + m_CharTu;
		vertex[2].tu = (m_OutputString[i] - m_AsciiCodeSpace) * m_CharTu + m_CharTu;
		vertex[3].tu = (m_OutputString[i] - m_AsciiCodeSpace) * m_CharTu;
		Renderer::GetInstance().Draw(vertex, "Picture\\Font.png");
	}
}