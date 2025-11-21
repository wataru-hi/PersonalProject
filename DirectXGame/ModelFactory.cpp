#include "ModelFactory.h"
using namespace KamataEngine;
std::map<std::string, std::shared_ptr<KamataEngine::Model>> ModelFactory::ModelData;

std::shared_ptr<Model> ModelFactory::CreateOrLoadModel(std::string modelFileName, bool sommthing) {
	// キャッシュのキーを作成 (スムース設定も考慮)
	std::string key = modelFileName + (sommthing ? "_smooth" : "_flat");

	// 既にロードされているかチェック
	if (ModelData.count(key)) {
		return ModelData.at(key);
	}

	// ロードされていない場合は新規作成 (Engine::Model::CreateFromOBJは共有ポインタを返す前提)
	std::shared_ptr<Model> newModel = std::make_unique<Model>(Model::CreateFromOBJ(modelFileName, sommthing));

	// キャッシュに格納
	ModelData[key] = newModel;
	return newModel;
}

void ModelFactory::ClearModel() { ModelData.clear(); }
