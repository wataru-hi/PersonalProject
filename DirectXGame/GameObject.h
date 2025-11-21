#pragma once
#include <KamataEngine.h>
#include <memory>
//#include "Event.h"

class GameObject {
public:
	GameObject() {}

	virtual ~GameObject() {}

	virtual void Initialize(std::string modelName);

	virtual void Update();

	void Draw(const KamataEngine::Camera& camera);

	KamataEngine::Vector3 const GetTranslation() { return worldTransform.translation_; }
	void SetTranslation(KamataEngine::Vector3 translation) { worldTransform.translation_ = translation; }
	//void SetTranslation(KamataEngine::Vector3 vel);
	void SetVelocity(KamataEngine::Vector3 vel);

	void SetRadius(KamataEngine::Vector2 radius) { radius_  = radius; }

	KamataEngine::Vector2 GetRadius() const { return radius_; }

protected:
	virtual void DrawImguiContent();

	std::unique_ptr<KamataEngine::Model> model;
	KamataEngine::WorldTransform worldTransform;

	KamataEngine::Vector3 velocity_;
	float moveSpeed = 0.3f;

	KamataEngine::Vector2 radius_ = {1.0f, 1.0f};
};