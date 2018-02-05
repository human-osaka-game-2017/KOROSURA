/**
 * @file	BoxCollider.h
 * @brief	直方体あたり判定クラスの定義
 * @author	shiraishi
 */
#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ColliderBase.h"
#include "Shape.h"

 /**
  * @brief		直方体あたり判定クラス
  * @details	直方体であたり判定したいときは、ObjectBaseクラスを継承し、OBBクラスを作って、このクラスを作る。
  */
class BoxCollider: public ColliderBase{
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
	BoxCollider(const char* className, ObjectBase* pObject, Shape::OBB* pObb, std::function<void(std::vector<ObjectData*>*)> function, unsigned long categoryBits, unsigned long maskBits);

	/*** @brief		BoxColliderクラスのデストラクタ*/
	virtual ~BoxCollider();

	/**
	* @brief		OBBのゲッター
	* @return		const Shape::OBB&	OBB
	*/
	const Shape::OBB& GetObb() const
	{
		return *m_pObb;
	}

	/**
	* @brief		あたり判定関数
	* @param[in]	collider	あたり判定する相手collider
	* @return		bool		当たっていたらtrueそうでなかったらfalse
	* @details		OBBとSphereを識別し、あたり判定する。
	*/
	virtual bool Collide(const ColliderBase& collider) const;

private:
	bool CollideOBBToOBB(const BoxCollider& collider) const;
	FLOAT LenSegOnSeparateAxis(const D3DXVECTOR3& Sep, const D3DXVECTOR3& e1, const D3DXVECTOR3& e2, const D3DXVECTOR3* e3 = nullptr) const;
	Shape::OBB* m_pObb;
};
#endif