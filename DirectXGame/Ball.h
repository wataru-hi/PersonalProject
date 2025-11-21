#pragma once

#include <KamataEngine.h>

#include "GameObject.h"


//class Player;

class Ball : public GameObject {
public:
	Ball() {

	};
	~Ball() {}

	void Initialize();
	void Update() override;

	void OnCollision(KamataEngine::Vector3 refDir);

private:
	void DrawImgui();
	//Player* player_;

	const float moveSpeed = 0.3f;
	const float collisionDistance = 1.0f; // 衝突判定の距離
	float reflectionForce = 0.3f;         // プレイヤー衝突時の反射の強さ
	float distance = 0.3f;

	const KamataEngine::Vector2 boundary = {35.2f, 19.2f};
};
