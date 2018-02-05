/**
 * @file	BoxCollider.h
 * @brief	�����̂����蔻��N���X�̒�`
 * @author	shiraishi
 */
#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ColliderBase.h"
#include "Shape.h"

 /**
  * @brief		�����̂����蔻��N���X
  * @details	�����̂ł����蔻�肵�����Ƃ��́AObjectBase�N���X���p�����AOBB�N���X������āA���̃N���X�����B
  */
class BoxCollider: public ColliderBase{
public:
	/**
	 * @brief		BoxCollider�N���X�̃R���X�g���N�^
	 * @param[in]	className		�����҂̃N���X��
	 * @param[in]	pObject			�����҂�this�|�C���^
	 * @param[in]	pObb			���肷�邽�߂̒����̂̃|�C���^
	 * @param[in]	function		���������ۂɌĂ΂��֐� ���̊֐�����delete�͂��Ȃ�����
	 * @param[in]	categoryBits	�ǂ�Ƃ����蔻�肷�邩�𔻒莞�̎����̎��ʃr�b�g
	 * @param[in]	maskBits		�ǂ�Ƃ����蔻�肷�邩�𔻒莞�̑���̎��ʃr�b�g(�r�b�g�������Ă���z�Ɣ���)
	 */
	BoxCollider(const char* className, ObjectBase* pObject, Shape::OBB* pObb, std::function<void(std::vector<ObjectData*>*)> function, unsigned long categoryBits, unsigned long maskBits);

	/*** @brief		BoxCollider�N���X�̃f�X�g���N�^*/
	virtual ~BoxCollider();

	/**
	* @brief		OBB�̃Q�b�^�[
	* @return		const Shape::OBB&	OBB
	*/
	const Shape::OBB& GetObb() const
	{
		return *m_pObb;
	}

	/**
	* @brief		�����蔻��֐�
	* @param[in]	collider	�����蔻�肷�鑊��collider
	* @return		bool		�������Ă�����true�����łȂ�������false
	* @details		OBB��Sphere�����ʂ��A�����蔻�肷��B
	*/
	virtual bool Collide(const ColliderBase& collider) const;

private:
	bool CollideOBBToOBB(const BoxCollider& collider) const;
	FLOAT LenSegOnSeparateAxis(const D3DXVECTOR3& Sep, const D3DXVECTOR3& e1, const D3DXVECTOR3& e2, const D3DXVECTOR3* e3 = nullptr) const;
	Shape::OBB* m_pObb;
};
#endif