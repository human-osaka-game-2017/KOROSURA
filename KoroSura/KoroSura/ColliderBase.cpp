#include"ColliderBase.h"
#include"ObjectBase.h"

ColliderBase::ColliderBase(const char* className, ObjectBase* pObject, std::function<void(std::vector<ObjectData*>*)> function, unsigned long categoryBits, unsigned long maskBits, Shape::SHAPE_ID shapeId):
	m_ObjectData(className,pObject), m_Function(function), kCategoryBits(categoryBits), m_MaskBits(maskBits), kShapeId(shapeId)
{

}

float ColliderBase::GetLengthOBBToPoint(Shape::OBB &obb, D3DXVECTOR3 &pos)
{
	D3DXVECTOR3 Vec(0, 0, 0);

	for (int i = 0; i < 3; i++){
		float L = obb.GetLength(i);
		if (L <= 0) continue;  // L=0は計算できない
		float s = D3DXVec3Dot(&(pos - obb.GetPos()), &obb.GetDirect(i)) / L;

		// sの値から、はみ出した部分があればそのベクトルを加算
		s = fabs(s);
		if (s > 1)
			Vec += (1 - s)*L*obb.GetDirect(i);   // はみ出した部分のベクトル算出
	}

	return D3DXVec3Length(&Vec);   // 長さを出力
}