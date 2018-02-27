#include"MainScene.h"
#include"Lib.h"
#include"Slime.h"
#include"Terrain.h"
#include"Camera.h"
#include"Shader.h"
#include"ModelManager.h"
#include"Effect.h"
#include"DirLightSource.h"

MainScene::MainScene()
{
	m_View = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "View");
	m_Proj = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Proj");
	m_Light = FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->GetParameterByName(NULL, "Light");
}

MainScene::~MainScene()
{
}

SceneBase::SCENE_ID MainScene::Update()
{
	Lib::GetInstance().UpdateKey();
	Lib::GetInstance().UpdateMouse();
	SceneBase::SCENE_ID retSceneId = SCENE_ID::MAIN;
	return retSceneId;
}

void MainScene::Draw()
{
	//Effect‚²‚Æ‚É‚â‚ê‚Î‚¢‚¢
	D3DXMATRIX ViewMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_VIEW, &ViewMatrix);
	D3DXMATRIX ProjMatrix;
	(*DirectGraphics::GetInstance().GetDevice())->GetTransform(D3DTS_PROJECTION, &ProjMatrix);
	D3DXMATRIX WorldMatrix;

	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_View, &ViewMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetMatrix(m_Proj, &ProjMatrix);
	FxManager::GetpInstance().GetFxEffect("Shader\\BasicShader.fx")->GetEffect()->SetVector(m_Light, &DirLightSource::GetpInstance().GetlightDir());
}
