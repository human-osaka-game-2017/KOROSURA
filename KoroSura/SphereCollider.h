#ifndef CIRCLECOLLDER_H
#define CIRCLECOLLDER_H

#include"ColliderBase.h"

class SphereCollider :public ColliderBase{
public:
	/**
	* @brief		BoxColliderクラスのコンストラクタ
	* @param[in]	className		生成者のクラス名
	* @param[in]	pObject			生成者のthisポインタ
	* @param[in]	pObb			判定するための直方体のポインタ
	* @param[in]	function		当たった際に呼ばれる関数 この関数内でdeleteはしないこと
	* @param[in]	categoryBits	どれとあたり判定するかを判定時の自分の識別ビット
	* @param[in]	maskBits		どれとあたり判定するかを判定時の相手の識別ビット(ビットが立っている奴と判定)
	*/
	SphereCollider(const char* className, ObjectBase* pObject, Shape::Sphere* pSphere, std::function<void(std::vector<ObjectData*>*)> function,
		unsigned long categoryBits, unsigned long maskBits);

	virtual ~SphereCollider();

private:
	Shape::Sphere* m_pSphere;
};
#endif