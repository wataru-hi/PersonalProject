#include "ModelObject.h"

using namespace KamataEngine;

void ModelObject::LoadModel(std::string modelFileName, bool smoothShading) {
	modelData.model = Modelfactory->CreateOrLoadModel(modelFileName, smoothShading);
	modelData.worldT.Initialize();/*
	modelData.obJectC.Initialize();
	modelData.obJectC.SetColor(Vector4{1.0f, 1.0f, 1.0f, 1.0f});*/
}

void ModelObject::Update() { 


	modelData.worldT.Updatematrix();
}

void ModelObject::Draw(const KamataEngine::Camera& camera) {
	modelData.model->Draw(modelData.worldT, camera); 
}