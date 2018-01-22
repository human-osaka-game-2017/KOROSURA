/**
 * @file	Shape.h
 * @brief	直方体・矩形・球・円クラス、ShapeID
 * @author	shiraishi
 */
#ifndef SHAPE_H
#define SHAPE_H

#include <d3dx9.h>

 /**
  * @namespace	Shape
  * @brief		直方体・矩形・球・円クラス、ShapeIDを定義
  * @details	ここで定義される各クラスはColliderに持たせ、当たり判定に使用。ShapeIDは識別ID。
  */
namespace Shape {

	/** @enum	SHAPE_ID
	 *  @brief  形識別ID
	 */
	enum struct SHAPE_ID {
		SQUARE,	//! 2D 矩形
		CIRCLE,	//! 2D 円
		BOX,	//! 3D 直方体
		SPHERE,	//! 3D 球
	};

	/**
	 * @brief	直方体クラス
	 * @details 位置、方向ベクトル３つ、長さ３つを持ち、BoxColliderクラスが保持するクラス
	 */
	class OBB {
	public:
		/*** @brief OBBクラスのコンストラクタ*/
		OBB() {};

		/*** @brief OBBクラスのデストラクタ*/
		virtual ~OBB() {};

		/**
		 * @brief		位置を取得
		 * @return		D3DXVECTOR3&	位置ベクトル
		 */
		D3DXVECTOR3& GetPos()
		{
			return m_Pos;
		}

		/**
		 * @brief		位置を設定
		 * @param[in]	pos	位置
		 */
		void SetPos(const D3DXVECTOR3& pos)
		{
			m_Pos = pos;
		}

		/**
		 * @brief		指定軸番号の方向ベクトルを取得
		 * @param[in]	index			取得したい方向ベクトルの番号
		 * @return		D3DXVECTOR3&	方向ベクトル
		 */
		D3DXVECTOR3& GetDirect(int index)
		{
			return m_NormaDirect[index];
		}

		/**
		 * @brief		方向ベクトルを設定
		 * @param[in]	index	設定したい方向ベクトル軸番号
		 * @param[in]	direct	方向ベクトル(単位ベクトルのため長さは１にする)
		 */
		void SetDirect(int index, const D3DXVECTOR3& direct)
		{
			m_NormaDirect[index] = direct;
		}

		/**
		 * @brief		指定軸方向の長さを取得
		 * @param[in]	index			取得したい長さの番号
		 * @return		float			指定軸方向の長さ
		 */
		FLOAT GetLength(int index)
		{
			return m_Length[index];
		}

		/**
		* @brief		指定軸方向の長さを設定
		* @param[in]	index	設定したい長さの軸番号
		* @param[in]	length	長さ
		*/
		void SetLength(int index, float length)
		{
			m_Length[index] = length;
		}

		/**
		 * @brief		直方体を回転させる関数
		 * @param[in]	axisIndex	回転させる際の中心になる軸番号
		 * @param[in]	deg			現在の状態から何度回転させるかの角度（度数）
		 * @details		第一引数を中心に第二引数分回転させる
		 */
		void Rotation(int axisIndex, float deg);

	private:
		D3DXVECTOR3 m_Pos;				//! 位置
		D3DXVECTOR3 m_NormaDirect[3];	//! 方向ベクトル
		FLOAT m_Length[3];				//! 各軸方向の長さ
	};
}

#endif