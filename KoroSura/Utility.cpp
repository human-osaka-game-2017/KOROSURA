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

bool Utility::JudgeCollisionCircle(const D3DXVECTOR2& pos1, float r1, const D3DXVECTOR2& pos2, float r2)
{
	float sumR = r1 + r2;

	float L = (float)pow(pos1.x - pos2.x, 2) + (float)pow(pos1.y - pos2.y, 2);
	L = (float)sqrt(L);

	if (sumR >= L) {
		return true;
	}
	return false;
}

bool Utility::JudgeCollisionSquare(const D3DXVECTOR2& pos1, float width1, float height1, const D3DXVECTOR2& pos2, float width2, float height2)
{
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

double Utility::CalculateDegree(float x1, float y1, float x2, float y2)
{
	D3DXVECTOR2 tmp = D3DXVECTOR2(x2 - x1, y2 - y1);

	return MyAtanDeg(tmp);
}

float Utility::MyAtanDeg(const D3DXVECTOR2& vec)
{
	float rad;

	if (vec.x == 0 && vec.y == 0) {
		return 0;
	}

	if (vec.x > 0) {
		if (vec.y < 0) {
			rad = atan(vec.y / vec.x);
		}
		else {
			rad = atan(vec.y / vec.x);
		}
	}
	else if (vec.x < 0) {
		rad = atan(vec.y / vec.x) + D3DX_PI;
	}
	else if (vec.x == 0) {
		if (vec.y < 0) {
			rad = D3DX_PI / 2;
		}
		else {
			rad = 3 / 2 * D3DX_PI;
		}
	}

	return D3DXToDegree(rad);
}

float Utility::CalculateDeg(float x1, float y1, float x2, float y2) 
{
	return (float)D3DXToDegree(CalculateDegree(x1, y1, x2, y2));
}

float Utility::CalculateDistance(float x1, float y1, float x2, float y2) 
{
	return (float)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Utility::OutputDebug_Number(float outputNum, HWND hWnd) 
{
	TCHAR buff[256];
	_stprintf_s(buff, 256, _T("%f\n"), outputNum);
	OutputDebugString(buff);
	SetWindowText(hWnd, buff);
}

void Utility::OutputDebug_Number(float outputNum) 
{
	TCHAR buff[256];
	_stprintf_s(buff, 256, _T("%f\n"), outputNum);
	OutputDebugString(buff);
}

Matrix* Utility::GetRotationXMatrix(Matrix* mat, float deg)
{
	float rad = D3DXToRadian(deg);
	*mat = Matrix(3, 3,
		1.0, 0.0, 0.0,
		0.0, cos(rad), -sin(rad),
		0.0, sin(rad), cos(rad));

	return mat;
}

Matrix* Utility::GetRotationYMatrix(Matrix* mat, float deg)
{
	float rad = D3DXToRadian(deg);
	*mat = Matrix(3, 3,
		cos(rad), 0.0, sin(rad),
		0.0, 1.0, 0.0,
		-sin(rad), 0.0, cos(rad));

	return mat;
}

Matrix* Utility::GetRotationZMatrix(Matrix* mat, float deg)
{
	float rad = D3DXToRadian(deg);
	*mat = Matrix(3, 3,
		cos(rad), -sin(rad), 0.0,
		sin(rad), cos(rad), 0.0,
		0.0, 0.0, 1.0);

	return mat;
}

D3DXVECTOR3* Utility::Tilt(D3DXVECTOR3* vector, float deg)
{
	float rad;
	rad = D3DXToRadian(deg);

	float length = D3DXVec3Length(vector);

	float theta1 = asin(vector->y / length);
	float theta2 = acos(vector->x / length*cos(theta1));

	vector->x += length*(float)cos(theta1 + rad)*(float)cos(theta2);
	vector->y += length*(float)sin(theta1 + rad);
	vector->z += length*(float)cos(theta1 + rad)*(float)sin(theta2);

	return vector;
}

D3DXVECTOR3* Utility::VecOBBToPoint(const Shape::OBB& obb, const D3DXVECTOR3& p, D3DXVECTOR3* out)
{
	*out = D3DXVECTOR3(0, 0, 0);   // 最終的に長さを求めるベクトル

	// 各軸についてはみ出た部分のベクトルを算出
	for (int i = 0; i<3; i++)
	{
		FLOAT L = obb.GetLength(i);
		if (L <= 0) continue;  // L=0は計算できない
		FLOAT s = D3DXVec3Dot(&(p - obb.GetPos()), &obb.GetDirect(i)) / L;

		// sの値から、はみ出した部分があればそのベクトルを加算
		s = fabs(s);
		if (s > 1)
			*out += (1 - s)*L*obb.GetDirect(i);   // はみ出した部分のベクトル算出
	}

	return out;   // 長さを出力
}

char Utility::TransformChar(int val)
{
	char ret;

	switch (val) {
	case 0:
		ret = '0';
		break;

	case 1:
		ret = '1';
		break;

	case 2:
		ret = '2';
		break;

	case 3:
		ret = '3';
		break;

	case 4:
		ret = '4';
		break;

	case 5:
		ret = '5';
		break;

	case 6:
		ret = '6';
		break;

	case 7:
		ret = '7';
		break;

	case 8:
		ret = '8';
		break;

	case 9:
		ret = '9';
		break;
	}

	return ret;
}