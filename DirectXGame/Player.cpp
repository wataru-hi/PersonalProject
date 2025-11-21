#include "Player.h"
using namespace KamataEngine;
using namespace MathUtility;

void Player::Initialize() {
	GameObject::Initialize("player");

	worldTransform.scale_ = Vector3{2.0f, 2.0f, 2.0f};
	bodyDirection_ = Vector3Zero();
}

void Player::Update() {

	CheckKey();
	bodyDirection_ = Vector3Zero();
	velocity_ = Vector3Zero();

	if (upKey) {
		velocity_.y = moveSpeed;
		bodyDirection_.y = 1.0f;
	}
	if (downKey) {
		velocity_.y = -moveSpeed;
		bodyDirection_.y = -1.0f;
	}
	if (leftKey) {
		velocity_.x = -moveSpeed;
		bodyDirection_.x = -1.0f;
	}
	if (rightKey) {
		velocity_.x = moveSpeed;
		bodyDirection_.x = 1.0f;
	}

	CheckBodyDirection();

	GameObject::Update();

#ifdef _DEBUG
	DrawImgui();
#endif
}

void Player::CheckBodyDirection() {
	
}

void Player::DrawImgui() {
	ImGui::Begin("player");
	GameObject::DrawImguiContent();
	ImGui::Separator();
	//ImGui::DragFloat("rad_a", &angleRad, 0.01f);
	ImGui::End();
}

void Player::CheckKey() {
	upKey = Input::GetInstance()->PushKey(DIK_W) || Input::GetInstance()->PushKey(DIK_UP);
	downKey = Input::GetInstance()->PushKey(DIK_S) || Input::GetInstance()->PushKey(DIK_DOWN);
	leftKey = Input::GetInstance()->PushKey(DIK_A) || Input::GetInstance()->PushKey(DIK_LEFT);
	rightKey = Input::GetInstance()->PushKey(DIK_D) || Input::GetInstance()->PushKey(DIK_RIGHT);
}