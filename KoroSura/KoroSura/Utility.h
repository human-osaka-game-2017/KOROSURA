#ifndef UTILITY_H
#define UTILITY_H

#include<d3dx9.h>

namespace Utility {
	struct CUSTOMVERTEX {
		FLOAT	x, y, z, rhw;
		DWORD	color;
		FLOAT	tu, tv;
	};

	enum BUTTON_STATE {
		OFF,	//!< �O�t���[�����痣����Ă�����
		ON,		//!< �O�t���[�����牟����Ă�����
		PUSH,	//!< ���t���[�����牟���ꂽ���
		RELEASE	//!< ���t���[�����痣���ꂽ���
	};

	enum KEY_KIND
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_0,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		SPACE,
		LSHIFT,
		RSHIFT,
		LCONTROL,
		RCONTROL,
		ESC,
		MAX
	};

	struct MOUSE_DATA {
		int Dim_x;					//!< �}�E�X��X�̈ړ���
		int Dim_y;					//!< �}�E�X��Y�̈ړ���
		int Dim_z;					//!< �}�E�X��Z�̈ړ���
		BUTTON_STATE LeftMouse;		//!< �}�E�X�̍��N���b�N�̏��
		BUTTON_STATE RightMouse;	//!< �}�E�X�̉E�N���b�N�̏��
	};

	struct PICTURE_INFO {
		LPDIRECT3DTEXTURE9 texture;
		int width;
		int height;
	};

	bool JudgeCollisionCircle(const D3DXVECTOR2& pos1, float r1, const D3DXVECTOR2& pos2, float r2);

	bool JudgeCollisionSquare(const D3DXVECTOR2& pos1, float width1, float height1, const D3DXVECTOR2& pos2, float width2, float height2);

	float CalculateDistance(float x1, float y1, float x2, float y2);

	float CalculateDeg(float x1, float y1, float x2, float y2);

	double CalculateRad(float x1, float y1, float x2, float y2);

	void OutputDebug_Number(float outputNum, HWND hWnd);

	//min<= random <= max
	int Random(int min, int max);
}
#endif
