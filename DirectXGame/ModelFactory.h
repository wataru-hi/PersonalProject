#pragma once
#include <KamataEngine.h>

#include <map>

class ModelFactory {
public:
	std::shared_ptr<KamataEngine::Model> CreateOrLoadModel(std::string modelFileName, bool sommthing);

	void ClearModel();

private:
	ModelFactory() = delete;
	~ModelFactory() = delete;

	static std::map<std::string, std::shared_ptr<KamataEngine::Model>> ModelData;

};
