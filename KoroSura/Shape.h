/**
 * @file	Shape.h
 * @brief	�����́E��`�E���E�~�N���X�AShapeID
 * @author	shiraishi
 */
#ifndef SHAPE_H
#define SHAPE_H

#include <d3dx9.h>

 /**
  * @namespace	Shape
  * @brief		�����́E��`�E���E�~�N���X�AShapeID���`
  * @details	�����Œ�`�����e�N���X��Collider�Ɏ������A�����蔻��Ɏg�p�BShapeID�͎���ID�B
  */
namespace Shape {

	/** @enum	SHAPE_ID
	 *  @brief  �`����ID
	 */
	enum struct SHAPE_ID {
		SQUARE,	//! 2D ��`
		CIRCLE,	//! 2D �~
		BOX,	//! 3D ������
		SPHERE,	//! 3D ��
	};

	/**
	 * @brief	�����̃N���X
	 * @details �ʒu�A�����x�N�g���R�A�����R�������ABoxCollider�N���X���ێ�����N���X
	 */
	class OBB {
	public:
		/*** @brief OBB�N���X�̃R���X�g���N�^*/
		OBB() {};

		/*** @brief OBB�N���X�̃f�X�g���N�^*/
		virtual ~OBB() {};

		/**
		 * @brief		�ʒu���擾
		 * @return		D3DXVECTOR3&	�ʒu�x�N�g��
		 */
		D3DXVECTOR3& GetPos()
		{
			return m_Pos;
		}

		/**
		 * @brief		�ʒu��ݒ�
		 * @param[in]	pos	�ʒu
		 */
		void SetPos(const D3DXVECTOR3& pos)
		{
			m_Pos = pos;
		}

		/**
		 * @brief		�w�莲�ԍ��̕����x�N�g�����擾
		 * @param[in]	index			�擾�����������x�N�g���̔ԍ�
		 * @return		D3DXVECTOR3&	�����x�N�g��
		 */
		D3DXVECTOR3& GetDirect(int index)
		{
			return m_NormaDirect[index];
		}

		/**
		 * @brief		�����x�N�g����ݒ�
		 * @param[in]	index	�ݒ肵���������x�N�g�����ԍ�
		 * @param[in]	direct	�����x�N�g��(�P�ʃx�N�g���̂��ߒ����͂P�ɂ���)
		 */
		void SetDirect(int index, const D3DXVECTOR3& direct)
		{
			m_NormaDirect[index] = direct;
		}

		/**
		 * @brief		�w�莲�����̒������擾
		 * @param[in]	index			�擾�����������̔ԍ�
		 * @return		float			�w�莲�����̒���
		 */
		FLOAT GetLength(int index)
		{
			return m_Length[index];
		}

		/**
		* @brief		�w�莲�����̒�����ݒ�
		* @param[in]	index	�ݒ肵���������̎��ԍ�
		* @param[in]	length	����
		*/
		void SetLength(int index, float length)
		{
			m_Length[index] = length;
		}

		/**
		 * @brief		�����̂���]������֐�
		 * @param[in]	axisIndex	��]������ۂ̒��S�ɂȂ鎲�ԍ�
		 * @param[in]	deg			���݂̏�Ԃ��牽�x��]�����邩�̊p�x�i�x���j
		 * @details		�������𒆐S�ɑ���������]������
		 */
		void Rotation(int axisIndex, float deg);

	private:
		D3DXVECTOR3 m_Pos;				//! �ʒu
		D3DXVECTOR3 m_NormaDirect[3];	//! �����x�N�g��
		FLOAT m_Length[3];				//! �e�������̒���
	};
}

#endif