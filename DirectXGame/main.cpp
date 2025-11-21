#include <Windows.h>

#include "GameScene.h"
#include <KamataEngine.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	KamataEngine::Initialize(L"3065_Switching of Geist");

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	ImGuiManager* imGuiManager = ImGuiManager::GetInstance();

	std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();
	gameScene->Initialize();

	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		// 更新処理
		imGuiManager->Begin();

		gameScene->Update();
		imGuiManager->End();

		// 描画開始

		dxCommon->PreDraw();

		dxCommon->ClearDepthBuffer();
		// 描画処理
		Model::PreDraw();

		gameScene->Draw();

		Model::PostDraw();

		imGuiManager->Draw();
		// 描画終了

		dxCommon->PostDraw();
	}

	return 0;
}
