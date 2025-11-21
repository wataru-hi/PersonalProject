#include "Ball.h"
//#include "Player.h"

using namespace KamataEngine;
using namespace MathUtility;

void Ball::Initialize() {
	GameObject::Initialize("cube");
	worldTransform.translation_.x = 3.0f;
	worldTransform.scale_ = Vector3{0.5f, 0.5f, 0.5f};

	velocity_ = Vector3Zero();

	SetRadius(Vector2(worldTransform.scale_.x, worldTransform.scale_.y));
}

void Ball::Update() { 
	//velocity_ = Vector3Zero();

	//Vector3 diff = worldTransform.translation_;
	//
	// diff -= (player_->GetTranslation());
	// distance = Length(diff);        // ベクトルの長さを計算
	//
	//if (distance < collisionDistance) {
	//	// 衝突時のボールの反射処理
	//	velocity_ = MathUtility::Normalize(diff) * reflectionForce;
	//}

	 if (std::abs(worldTransform.translation_.x) >= boundary.x) {
		velocity_.x = -velocity_.x;                                                                   // x方向の速度を反転
		worldTransform.translation_.x = (worldTransform.translation_.x > 0) ? boundary.x : -boundary.x; // 境界内に戻す
	 }

	 if (std::abs(worldTransform.translation_.y) >= boundary.y) {
		 velocity_.y = -velocity_.y;                                                                   // y方向の速度を反転
		 worldTransform.translation_.y = (worldTransform.translation_.y > 0) ? boundary.y : -boundary.y; // 境界内に戻す
	 }

#ifdef _DEBUG
	 
	 DrawImgui();
#endif // _DEBUG


	GameObject::Update();
}

void Ball::OnCollision(Vector3 refDir) { 
	velocity_ = refDir * reflectionForce;
}

void Ball::DrawImgui() {
	ImGui::Begin("Ball");
	GameObject::DrawImguiContent();
	ImGui::End();
}