#ifndef CAMERAIVENT_H
#define CAMERAIVENT_H

#include"Lib.h"
class CameraIvent {
public:
	static CameraIvent& CameraIvent::GetInstance() {
		if (m_pInstance == nullptr) {
			m_pInstance = new CameraIvent();
		}
		return *m_pInstance;
	}
	D3DXVECTOR3 GetCameraPos(){
		return m_CameraPos;
	}
	void SetCameraPos(D3DXVECTOR3 pos) { m_CameraPos = pos; }
private:
	static CameraIvent* m_pInstance;
	CameraIvent() {};
	~CameraIvent() {};
	D3DXVECTOR3		m_CameraPos;
};


#endif