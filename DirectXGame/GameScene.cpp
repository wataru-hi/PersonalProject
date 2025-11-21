#include "GameScene.h"

using namespace KamataEngine;
using namespace MathUtility;

void GameScene::Initialize() {
	camera = new Camera();
	camera->Initialize();

	player_ = std::make_shared<Player>();
	player_->Initialize();
	GameObjects.push_back(player_);

	ball_ = std::make_shared<Ball>();
	ball_->Initialize();
	GameObjects.push_back(ball_);
}

void GameScene::Update() {
	for (const auto& object : GameObjects) {
		object->Update();
	}

	CheckCollision();

#ifdef _DEBUG
	ImGui::Begin("camera");
	ImGui::DragFloat3("cameraPos", &camera->translation_.x);
	ImGui::End();
#endif // _DEBUG

	camera->UpdateMatrix();
}

void GameScene::Draw() {
	if (!camera)
		return;

	for (const auto& object : GameObjects) {
		object->Draw(*camera);
	}
}

void GameScene::CheckCollision() {
	Vector3 ballPos = ball_->GetTranslation();
	Vector3 playerPos = player_->GetTranslation();

	float radiusA = player_->GetRadius().x;
	float radiusB = ball_->GetRadius().x;

	float diffX = ballPos.x - playerPos.x;
	float diffY = ballPos.y - playerPos.y;

	float distance = std::sqrt(diffX * diffX + diffY * diffY);

	float sumRadius = radiusA + radiusB;
	if (distance < sumRadius) {
		Vector3 diff = ballPos - playerPos;
		diff.z = 0.0f;

		Vector3 refDir = MathUtility::Normalize(diff);
		ball_->OnCollision(refDir);
	}
}

