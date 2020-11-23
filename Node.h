#pragma once

#include <list>
#include <map>

struct Point {
	int x, y;

	Point() {
		x = 0;
		y = 0;
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

struct NodeInfo {			// 노드의 정보
	enum Info
	{
		Moveable = 0,		// 현재 노드의 이동 가능성 (이동 가능)
		NotMoveable = 1,	// (이동 불가능)
		Start = 2,			// 출발 지점
		End = 3,			// 목표 지점	 
		Final = 7,
	};
};

class Node {

public:
	Node* parent;	// 해당 노드의 부모 노드
	Point location;	// 해당 노드의 위치 좌표
	NodeInfo::Info NodeInfo;
	int index;
	int G;			// 시작 좌표부터 현재 좌표까지의 거리
	int H;			// 현재 좌표부터 목표 좌표까지의 거리

	Node();
	~Node();

	int F() { return G + H; }	 // 휴리스틱 값
};