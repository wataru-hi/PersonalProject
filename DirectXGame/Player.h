#pragma once
#include <KamataEngine.h>

#include "GameObject.h"


class Player : public GameObject{
public:
	Player() {
	
	};
	~Player() = default;

	void Initialize();
	void Update() override;

private:
	void CheckBodyDirection();

	void DrawImgui();
	void CheckKey();

	KamataEngine::Vector2 mousePos;
	KamataEngine::Vector3 bodyDirection_;

	//float angleRad = 0.0f;

	bool upKey;
	bool downKey;
	bool leftKey;
	bool rightKey;
};
