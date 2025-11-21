#include "KamataEngine.h"

using namespace KamataEngine;
using namespace MathUtility;
Matrix4x4 MathUtility::MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = rotateXMatrix * rotateYMatrix * rotateZMatrix;
	Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
	Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);

	Matrix4x4 ret = scaleMatrix * rotateXYZMatrix * translateMatrix;

	return ret;
}

float MathUtility::Length(const Vector3& vec) {
	return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}


Vector3 MathUtility::Normalize(const Vector3& vec) {
	float len = Length(vec);
	if (len == 0.0f) {
		return Vector3{0.0f, 0.0f, 0.0f}; // 長さが0の場合はゼロベクトルを返す
	}
	return Vector3{vec.x / len, vec.y / len, vec.z / len};
}