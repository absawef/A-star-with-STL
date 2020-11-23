#pragma once

#include <list>
#include "Node.h"
#include <vector>

using namespace std;

class MyMap {

private:
	int row = 0;
	int col = 0;
	vector<vector<Node>> created_node;

public:
	MyMap();
	~MyMap();

	void setRowCol(int row, int col) {
		this->row = row;
		this->col = col;
		this->created_node.resize(row, vector<Node>(col));
	}

	vector<vector<int>> CreatVectorArray(int row, int col);
	void CreateMap(Point& start, Point& end);	// 맵 생성
	void ShowMap(list<Node*> moveNodeList);		// 노드를 리스트에 담아서 출력
	Node* GetNode(int x, int y);				// (x,y) 값을 받아 노드 위치 get
	Node* GetNode(Point loc);					// location 값을 받아 노드 위치 get

};