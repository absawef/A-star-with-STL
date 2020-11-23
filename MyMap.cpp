#include "MyMap.h"
#include "Node.h"
#include <vector>
#include <random>
#include <iostream>

using namespace std;

MyMap::MyMap() { }
MyMap::~MyMap(){ }

vector<vector<int>> MyMap::CreatVectorArray(int row, int col) {
	vector<int> vec(col, 0);
	vector<vector<int>> Array(row,vec);

	random_device rd;							// 난수 함수
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1);	// 0 or 1 생성

	for (int x = 0; x < col; x++) {
		for (int y = 0; y < row; y++) {
			Array[x][y] = dis(gen);
		}
	}

	return Array;
}

void MyMap::CreateMap(Point& startPoint, Point& endPoint) {
	vector<vector<int>> Vec2D_MapArray;
	Vec2D_MapArray = CreatVectorArray(row, col);

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {

			Node* curNode = &created_node[x][y];
			int NodeInfo = Vec2D_MapArray[x][y];

			curNode->NodeInfo = (NodeInfo::Info)NodeInfo;
			curNode->location.x = x;
			curNode->location.y = y;

			if (curNode->NodeInfo == NodeInfo::Start) {		// 현재 노드가 시작 지점이라면
				startPoint.x = x;
				startPoint.y = y;
			}
			else if(curNode->NodeInfo==NodeInfo::End){		// 현재 노드가 목표 지점이라면
				endPoint.x = x;
				endPoint.y = y;
			}
		}
	}

	cout << "Create Map" << endl<<endl;
}

void MyMap::ShowMap(list<Node*> moveNodeList) {		// 맵 출력
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			Node* curNode = &created_node[x][y];
			
			auto find = std::find(moveNodeList.begin(), moveNodeList.end(), curNode);	// 반복자 사용으로 현재 노드 출력
			if (find != moveNodeList.end())
				cout<<" ";
			else
				cout<<(int)curNode->NodeInfo<<" ";
		}
		cout << endl;
	}
}

Node* MyMap::GetNode(int x, int y) {			//좌표에 대한 노드를 get
	return GetNode(Point(x, y));
}

Node* MyMap::GetNode(Point loc) {
	if (loc.x < 0 || loc.x >= 10) return NULL;
	if (loc.y < 0 || loc.y >= 10) return NULL;

	return &created_node[loc.x][loc.y];
}