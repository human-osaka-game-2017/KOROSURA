#include "Description.h"
#include"Enlarger.h"
#include"StageInfo.h"
#include"Lib.h"

Description::Description()
{
	Lib::GetInstance().LoadPictureFile("Picture\\StageImg.png", kPngWidth, kPngHeight);
}

Description::~Description()
{
	Lib::GetInstance().CancelTexture("Picture\\StageImg.png");
}

void Description::Update()
{
}

void Description::Draw()
{
	float leftTopTu = GetLeftTopTu();

	//img画像の表示
	Utility::CUSTOMVERTEX picVertex[] = {
		{ kStagePicPos.x - kStagePicWidth / 2,kStagePicPos.y - kStagePicHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kStagePicPos.x + kStagePicWidth / 2,kStagePicPos.y - kStagePicHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kStagePicPos.x + kStagePicWidth / 2,kStagePicPos.y + kStagePicHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kStagePicPos.x - kStagePicWidth / 2,kStagePicPos.y + kStagePicHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		picVertex, 
		leftTopTu, 0.0f, 
		static_cast<float>(kStagePicWidth),static_cast<float>(kStagePicHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

	Lib::GetInstance().Draw(picVertex, "Picture\\StageImg.png");

	//text画像の表示
	Utility::CUSTOMVERTEX txtVertex[] = {
		{ kStageTxtPos.x - kStageTxtWidth / 2,kStageTxtPos.y - kStageTxtHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,0.0f },
		{ kStageTxtPos.x + kStageTxtWidth / 2,kStageTxtPos.y - kStageTxtHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,0.0f },
		{ kStageTxtPos.x + kStageTxtWidth / 2,kStageTxtPos.y + kStageTxtHeight / 2 ,1.0f,1.0f,0xffffffff ,1.0f,1.0f },
		{ kStageTxtPos.x - kStageTxtWidth / 2,kStageTxtPos.y + kStageTxtHeight / 2 ,1.0f,1.0f,0xffffffff ,0.0f,1.0f }
	};

	Lib::GetInstance().TrimingVertex(
		txtVertex,
		leftTopTu, 550.0f,
		static_cast<float>(kStageTxtWidth), static_cast<float>(kStageTxtHeight),
		static_cast<float>(kPngWidth), static_cast<float>(kPngHeight));

	Lib::GetInstance().Draw(txtVertex, "Picture\\StageImg.png");
}

float Description::GetLeftTopTu()
{
	int ret = 0;

	//アンロックされていなければ灰色画像
	if (StageInfo::GetInstance().GetUnLockingStage() <= m_SelectPoint) {

		ret = kStagePicWidth * 8;
	}
	else {
		ret = kStagePicWidth*m_SelectPoint;
	}

	return static_cast<float>(ret);
}