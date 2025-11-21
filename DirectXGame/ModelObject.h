#pragma once
#include <KamataEngine.h>

#include "ModelFactory.h"

struct ModelInfo {
	std::shared_ptr<KamataEngine::Model> model;
	KamataEngine::WorldTransform worldT;
	//ObjectColor obJectC;
};

class ModelObject {
public:
	ModelObject() {};
	~ModelObject() {};

	void LoadModel(std::string modelFailName, bool sommthing);
	void Update();
	void Draw(const KamataEngine::Camera& camera);

   const KamataEngine::Model* GetModel() const { return modelData.model.get(); }
	KamataEngine::WorldTransform& GetWorldTransform() { return modelData.worldT; }

private:
	ModelInfo modelData;

	std::unique_ptr<ModelFactory> Modelfactory;
};
