#ifndef SHAPE_H
#define SHAPE_H

#include<d3dx9.h>
#include"ObjectBase.h"

namespace Shape {

	enum SHAPE_ID {
		SQUARE,	//2D 四角形
		CIRCLE,	//2D 円
		BOX,	//3D 直方体
		SPHERE,	//3D 球
	};

	//class OBB: public ObjectBase {
	//public:
	//	OBB();
	//	virtual ~OBB(){}

	//	virtual void Update() = 0;
	//	virtual void Draw() = 0;

	//	D3DXVECTOR3& GetDirect(int elem);   // 指定軸番号の方向ベクトルを取得
	//	FLOAT GetLen(int elem);				// 指定軸方向の長さを取得
	//	D3DXVECTOR3& GetPos();				// 位置を取得
	//	void SetDirect(int elem, float deg);
	//	void Rotation(int elem, float deg);

	//protected:
	//	D3DXVECTOR3 m_Pos;              // 位置
	//	D3DXVECTOR3 m_NormaDirect[3];   // 方向ベクトル
	//	FLOAT m_fLength[3];             // 各軸方向の長さ
	//};
}

#endif