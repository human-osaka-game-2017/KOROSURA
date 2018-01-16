#include"Lib.h"
#include"DirectGraphics.h"
#include"DirectInput.h"
#include"Renderer.h"
#include"ModelManager.h"
#include"TextureManager.h"
#include"SoundBufferManager.h"
#include"DirectSound.h"

using namespace Utility;

Lib* Lib::pInstance = nullptr;

void Lib::CreateInstance(HWND hWnd, HINSTANCE hInstance){
	if (pInstance == nullptr) {
		pInstance = new Lib(hWnd, hInstance);
	}
}

Lib& Lib::GetInstance() {
	if (pInstance == nullptr) {
		MessageBox(0, "DirectInputインスタンスが生成されていません", NULL, MB_OK);
	}
	return *pInstance;
}

Lib::Lib(HWND hWnd, HINSTANCE hInstance){
	DirectGraphics::CreateInstance(hWnd);
	DirectInput::CrateInstance(hWnd, hInstance);
	DirectSound::CreateInstance(hWnd);
	Renderer::CreateInstance();
	ModelManager::CreateInstance();
	TextureManager::CreateInstance();

	m_pDirectGraphics = &DirectGraphics::GetInstance();
	m_pDirectInput = &DirectInput::GetInstance();
	m_pRenderer = &Renderer::GetInstance();
	m_pModelManager = &ModelManager::GetInstance();
	m_pTextureManager = &TextureManager::GetInstance();
	m_pSoundBufferManager = &SoundBufferManager::GetInstance();
}

Lib::~Lib() {
	delete pInstance;
}

void Lib::UpdateKey() {
	m_pDirectInput->UpdateKey();
}

void Lib::UpdateMouse() {
	m_pDirectInput->UpdateMouse();
}

BUTTON_STATE Lib::GetKeyState(KEY_KIND keyKind) {
	return m_pDirectInput->GetKeyState(keyKind);
}

const MOUSE_DATA* Lib::GetMouseData() {
	return m_pDirectInput->GetMouseData();
}

void Lib::CancelModel(const char* fileName) {
	m_pModelManager->CancelMesh(fileName);
}

HRESULT Lib::LoadXFile(const char* fileName) {
	return m_pModelManager->LoadXFile(fileName);
}

void Lib::TransformWorld(const D3DXVECTOR3& pPos, float degHeading, float degPitch, float degBank, float scale) {
	m_pRenderer->TransformWorld(pPos,degHeading,degPitch,degBank,scale);
}

void Lib::TransformView(const D3DXVECTOR3& pCameraPos, const D3DXVECTOR3&  LookatPos, const D3DXVECTOR3& UpVec) {
	m_pRenderer->TransformView(pCameraPos, LookatPos, UpVec);
}

D3DXVECTOR3* Lib::GetLookatPos(D3DXVECTOR3* pos, float length, float degHeading, float degBank) {
	return m_pRenderer->GetLookatPos(pos, length, degHeading, degBank);
}

void Lib::TransformProjection(float angle, float aspectRatio, float mimDistance, float maxDistance) {
	m_pRenderer->TransformProjection(angle, aspectRatio, mimDistance, maxDistance);
}

void Lib::SetRenderState2D() {
	m_pDirectGraphics->SetRenderState2D();
}

void Lib::SetRenderState3D() {
	m_pDirectGraphics->SetRenderState3D();
}

void Lib::StartRender() {
	m_pRenderer->StartRender();
}

void Lib::StartDraw(int red, int green, int blue) {
	m_pRenderer->StartDraw(red, green, blue);
}

bool Lib::Draw(const D3DXVECTOR2& pos, const char* fileName, float width, float height, float tu, float tv, float deg, float magnifying, DWORD color, bool flipHorizontal, bool flipVertical) {
	return m_pRenderer->Draw(pos, fileName, width, height, tu, tv, deg, magnifying, color, flipHorizontal, flipVertical);
}
bool Lib::Draw(const D3DXVECTOR3& pos, const char* fileName, float width, float height, float tu, float tv, float deg, float magnifying, DWORD color, bool flipHorizontal, bool flipVertical) {
	return m_pRenderer->Draw(pos, fileName, width, height, tu, tv, deg, magnifying, color, flipHorizontal, flipVertical);
}
bool Lib::Draw(const CUSTOMVERTEX vertex[], const char* fileName) {
	return m_pRenderer->Draw(vertex, fileName);
}

bool Lib::Render(const char* fileName) {
	return m_pRenderer->Render(fileName);
}

void Lib::EndRender() {
	m_pRenderer->EndRender();
}
void Lib::EndDraw() {
	m_pRenderer->EndDraw();
}

void Lib::TurnVertex_tu(CUSTOMVERTEX vertex[]) {
	m_pRenderer->TurnVertex_tu(vertex);
}

void Lib::TurnVertex_tv(CUSTOMVERTEX vertex[]) {
	m_pRenderer->TurnVertex_tv(vertex);
}

void Lib::ChangeScale(CUSTOMVERTEX vertex[], float magnifying) {
	m_pRenderer->ChangeScale(vertex, magnifying);
}

void Lib::TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight) {
	m_pRenderer->TrimingVertex(vertex, leftTopTu, leftTopTv, width, height, pngWidth, pngHeight);
}

void Lib::Rotation(CUSTOMVERTEX vertex[], float deg) {
	m_pRenderer->Rotation(vertex, deg);
}

void Lib::CancelTexture(const char* fileName) {
	m_pTextureManager->CancelTexture(fileName);
}

HRESULT Lib::LoadPictureFile(const char* fileName, int width, int height, bool canSemitransparent) {
	return m_pTextureManager->LoadPictureFile(fileName, width, height, canSemitransparent);
}

bool Lib::LoadWaveFile(const char* fileName) {
	return m_pSoundBufferManager->LoadWaveFile(fileName);
}

void Lib::CancelSound(std::string fileName) {
	m_pSoundBufferManager->CancelSound(fileName);
}

void Lib::PlayBackSound(std::string fileName, bool isLoop) {
	m_pSoundBufferManager->PlayBackSound(fileName, isLoop);
}

void Lib::StopSound(std::string fileName) {
	m_pSoundBufferManager->StopSound(fileName);
}