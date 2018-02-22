#ifndef CIRCLECOLLDER_H
#define CIRCLECOLLDER_H

#include"ColliderBase.h"

class SphereCollider :public ColliderBase{
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
	SphereCollider(const char* className, ObjectBase* pObject, Shape::Sphere* pSphere, std::function<void(std::vector<ObjectData*>*)> function,
		unsigned long categoryBits, unsigned long maskBits);

	virtual ~SphereCollider();

	const Shape::Sphere& GetSphere() const
	{
		return *m_pSphere;
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
	bool CollideOBBToSphere(const SphereCollider& collider) const;
	Shape::Sphere* m_pSphere;
};
#endif