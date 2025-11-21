#pragma once

#include <KamataEngine.h>

#include "Player.h"
#include "Ball.h"
#include "GameObject.h"

class GameScene {
public:
	GameScene() {
	
	};
	~GameScene() {
	
	};

	void Initialize();
	void Update();
	void Draw();

private:
	void CheckCollision();

	KamataEngine::Camera* camera;

	std::shared_ptr<Player> player_;
	std::shared_ptr<Ball> ball_;

	std::list<std::shared_ptr<GameObject>>GameObjects;
};
