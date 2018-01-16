#include"Utility.h"
#include<d3dx9.h>
#include<stdio.h>
#include<tchar.h>
#include<time.h>

//min<= random <= max
int Utility::Random(int min, int max)
{
	static bool seedrandom = false;

	if (seedrandom == false) {
		srand((unsigned int)time(NULL));
		seedrandom = true;
	}

	return min + rand() % (max-min + 1);
}

bool Utility::JudgeCollisionCircle(const D3DXVECTOR2& pos1, float r1, const D3DXVECTOR2& pos2, float r2) {
	float sumR = r1 + r2;

	float L = (float)pow(pos1.x - pos2.x, 2) + (float)pow(pos1.y - pos2.y, 2);
	L = (float)sqrt(L);

	if (sumR >= L) {
		return true;
	}
	return false;
}

bool Utility::JudgeCollisionSquare(const D3DXVECTOR2& pos1, float width1, float height1, const D3DXVECTOR2& pos2, float width2, float height2){
	D3DXVECTOR2 LeftTop1;
	D3DXVECTOR2 RightTop1;
	D3DXVECTOR2 LeftBottom1;
	D3DXVECTOR2 LeftTop2;
	D3DXVECTOR2 RightTop2;
	D3DXVECTOR2 LeftBottom2;

	LeftTop1.x = LeftBottom1.x = pos1.x - width1 / 2;
	RightTop1.x = pos1.x + width1 / 2;
	LeftTop1.y = RightTop1.y = pos1.y - height1 / 2;
	LeftBottom1.y = pos1.y + height1 / 2;
	LeftTop2.x = LeftBottom2.x = pos2.x - width2 / 2;
	RightTop2.x = pos2.x + width2 / 2;
	LeftTop2.y = RightTop2.y = pos2.y - height2 / 2;
	LeftBottom2.y = pos2.y + height2 / 2;

	if (LeftTop1.x < RightTop2.x) {
		if (LeftTop2.x < RightTop1.x) {
			if (LeftTop1.y < LeftBottom2.y) {
				if (LeftTop2.y < LeftBottom1.y) {
					return true;
				}
			}
		}
	}
	return false;
}

double Utility::CalculateRad(float x1, float y1, float x2, float y2) {
	double rad;

	double lengthX = x2 - x1;
	double lengthY = y2 - y1;

	if (0 < lengthX) {
		if (lengthY < 0) {
			rad = atan(lengthY / lengthX);
		}
		else {
			rad = atan(lengthY / lengthX) + (2 * D3DX_PI);
		}
	}
	else if (lengthX < 0) {
		rad = atan(lengthY / lengthX) + D3DX_PI;
	}
	else if (lengthX == 0) {
		if (0 < lengthY) {
			rad = 3 / 2 * D3DX_PI;
		}
		else {
			rad = D3DX_PI / 2;
		}
	}

	rad = (2 * D3DX_PI) - rad;

	return rad;
}

float Utility::CalculateDeg(float x1, float y1, float x2, float y2) {
	return (float)D3DXToDegree(CalculateRad(x1, y1, x2, y2));
}

float Utility::CalculateDistance(float x1, float y1, float x2, float y2) {
	return (float)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Utility::OutputDebug_Number(float outputNum, HWND hWnd) {
	TCHAR buff[256];
	_stprintf_s(buff, 256, _T("%f\n"), outputNum);
	OutputDebugString(buff);
	SetWindowText(hWnd, buff);
}