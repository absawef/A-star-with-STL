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
	void CreateMap(Point& start, Point& end);	// �� ����
	void ShowMap(list<Node*> moveNodeList);		// ��带 ����Ʈ�� ��Ƽ� ���
	Node* GetNode(int x, int y);				// (x,y) ���� �޾� ��� ��ġ get
	Node* GetNode(Point loc);					// location ���� �޾� ��� ��ġ get

};