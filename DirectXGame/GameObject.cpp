#include "GameObject.h"

using namespace KamataEngine;
using namespace MathUtility;

void GameObject::Initialize(std::string modelName) {
	model = std::unique_ptr<Model>(Model::CreateFromOBJ(modelName));
	worldTransform.Initialize();
}

void GameObject::Update() { 
	worldTransform.translation_ += velocity_;
	worldTransform.Updatematrix(); 
}

void GameObject::Draw(const KamataEngine::Camera& camera) {
	// ※Model::Drawの仕様が const Camera& を受け取れる前提です
	model->Draw(worldTransform, camera);
}
void GameObject::SetVelocity(Vector3 vel) { velocity_ = vel; }



void GameObject::DrawImguiContent() {
	ImGui::DragFloat3("scale", &worldTransform.scale_.x, 0.1f);
	ImGui::DragFloat3("rotate", &worldTransform.rotation_.x, 0.01f);
	ImGui::DragFloat3("translation", &worldTransform.translation_.x, 0.01f);
	ImGui::DragFloat3("velocity", &velocity_.x, 0.01f);
}
