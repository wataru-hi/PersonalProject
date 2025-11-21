#pragma once
#include <KamataEngine.h>
#include <functional>
#include <map>
#include <vector>

using namespace KamataEngine;

enum class EventType {
	PlayerPosition,
	PlayerTest,
	BallTest,
	BallTestVec3
};

using GenericCallback = std::function<void(EventType type, void* data)>;

class EventManager {
private:
	static inline std::map<EventType, std::vector<GenericCallback>> s_subscribers;

public:
		static void Subscribe(EventType type, GenericCallback callback) { s_subscribers[type].push_back(callback); }
	
		// 発行 (Publish)
	    static void Publish(EventType type, void* data) {
		    if (s_subscribers.count(type)) {
			    for (auto& callback : s_subscribers[type]) {
				    callback(type, data);
			    }
		    }
	    }
}

//// 1. イベントの種類を定義
//enum class EventType {
//	PlayerPositionUpdated,
//	BallStateChanged,
//	// ... 他のイベントをここに追加
//};
//
//// 2. イベントで伝達するデータ構造を定義
//struct PlayerPositionEvent {
//	Vector3 position;
//};
//
//// 3. コールバックの型。ここでは汎用性を高めるためvoid*でデータを渡す形にする
//using GenericCallback = std::function<void(EventType type, void* data)>;
//
//// 4. イベント管理の中核（シングルトンや静的クラスとして機能）
//class EventManager {
//private:
//	// イベントタイプと、それに対応するコールバック関数のリストを保持
//	static inline std::map<EventType, std::vector<GenericCallback>> s_subscribers;
//
//public:
//	// 購読 (Subscribe)
//	static void Subscribe(EventType type, GenericCallback callback) { s_subscribers[type].push_back(callback); }
//
//	// 発行 (Publish)
//	static void Publish(EventType type, void* data) {
//		if (s_subscribers.count(type)) {
//			for (auto& callback : s_subscribers[type]) {
//				callback(type, data);
//			}
//		}
//	}
};