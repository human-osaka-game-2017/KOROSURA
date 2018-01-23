#include"Fonts.h"
#include"Renderer.h"

namespace Fonts {
	const int g_Width = 56;
	const int g_Height = 98;
	const int g_PngSize = 1024;
}

Utility::CUSTOMVERTEX* Fonts::GetUV(const char ch, Utility::CUSTOMVERTEX* vertex)
{
	switch (ch) {
	case 'A':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 0, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'B':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 1, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'C':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 2, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'D':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 3, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'E':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 4, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'F':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 5, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'G':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 6, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'H':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 7, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'I':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 8, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'J':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 9, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'K':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 10, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'L':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 11, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'M':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 12, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'N':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 13, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'O':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 14, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'P':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 15, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'Q':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 16, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'R':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 17, g_Height * 0, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'S':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 0, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'T':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 1, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'U':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 2, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'V':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 3, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'W':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 4, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'X':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 5, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'Y':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 6, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'Z':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 7, g_Height * 1, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'a':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 0, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'b':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 1, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'c':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 2, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'd':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 3, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'e':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 4, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'f':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 5, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'g':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 6, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'h':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 7, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'i':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 8, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'j':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 9, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'k':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 10, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'l':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 11, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'm':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 12, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'n':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 13, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'o':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 14, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'p':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 15, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'q':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 16, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'r':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 17, g_Height * 2, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 's':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 0, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 't':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 1, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'u':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 2, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'v':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 3, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'w':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 4, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'x':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 5, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'y':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 6, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case 'z':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 7, g_Height * 3, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '0':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 0, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '1':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 1, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '2':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 2, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '3':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 3, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '4':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 4, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '5':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 5, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '6':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 6, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '7':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 7, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '8':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 8, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '9':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 9, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '!':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 10, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '?':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 11, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '+':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 12, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '*':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 13, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	case '-':
		Renderer::GetInstance().TrimingVertex(vertex, g_Width * 14, g_Height * 4, g_Width, g_Height, g_PngSize, g_PngSize);
		break;

	}
	return vertex;
}