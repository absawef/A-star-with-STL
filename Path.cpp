#include "Path.h"
#include "MyMap.h"
#include "Node.h"
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

Path::Path(MyMap* Map) { created_Map = Map; }
Path::~Path(){ }

list<Node*> Path::DoFindPath(Point Startloc, Point Endloc) {
	Node* goalNode = FindPath(Startloc, Endloc);
	if (goalNode == NULL)
		return list<Node*>();

	return Astar(goalNode);
}

list<Node*> Path::Astar(Node* endNode) {
	list<Node*> NodeList;
	list<Node*>::iterator iter;
	iter = NodeList.begin();

	if (endNode == NULL) return NodeList;

	Node* curNode = endNode;
	while (curNode->parent != NULL)
	{
		curNode->NodeInfo = NodeInfo::Final;		// (0,0) 출발 지점
		NodeList.push_back(curNode);
		curNode = curNode->parent;
		
		if (curNode->parent == NULL)
		{
			NodeList.push_back(curNode);			
			curNode->NodeInfo = NodeInfo::Final;	// (10,10) 목표지점
			break;
		}
		curNode->NodeInfo = NodeInfo::Final;		// 최적 경로
	}

	cout << "Find way !!" << endl;

	return NodeList;
}

Node* Path::FindPath(Point startloc, Point endloc) {
	list<Node*> openNodeList;
	unordered_set<Node*> closedNodeSet;

	Node* startNode = created_Map->GetNode(startloc);
	Node* endNode = created_Map->GetNode(endloc);

	startNode->parent = NULL;
	startNode->G = Path::G(startloc, endloc);
	startNode->H = Path::H(startloc, endloc);
	openNodeList.push_back(startNode);

	while (openNodeList.size()>0) {
		Node* curNode = GetBestF(openNodeList);
		if (curNode == NULL) break;

		closedNodeSet.insert(curNode);
		openNodeList.remove(curNode);

		if (curNode == endNode) return curNode;

		auto neighborList = GetNeighborList(curNode);
		auto startIter = neighborList.begin();
		auto endIter = neighborList.end();

		for (; startIter != endIter; startIter++) {
			Node* neighborNode = *startIter;

			if (neighborNode->NodeInfo == NodeInfo::NotMoveable) continue;

			if (closedNodeSet.find(neighborNode) != closedNodeSet.end()) continue;

			int G_cur2neighbor = Path::G(curNode, neighborNode);		// 현재 노드에서 이웃 노드까지 거리
			int G_start2cur = curNode->G;
			int G_start2neighbor = G_cur2neighbor + G_start2cur;

			auto find = std::find(openNodeList.begin(), openNodeList.end(), neighborNode);
			if (find == openNodeList.end()) {
				neighborNode->parent = curNode;
				neighborNode->G = G_start2neighbor;
				neighborNode->H = Path::H(neighborNode, endNode);

				openNodeList.push_back(neighborNode);
			}
			else {
				if (G_start2neighbor < neighborNode->G) {
					neighborNode->parent = curNode;
					neighborNode->G = G_start2neighbor;
				}
			}
		}
	}

	if (openNodeList.empty() == true)
		cout << "openNodeList is empty.." << endl;

	return NULL;
}

list<Node*> Path::GetNeighborList(Node* curNode) {
	list<Node*> neighborList;

	if (curNode == NULL)
		return neighborList;

	for (int x = -1; x <= 1; x++) {			// 현재 노드기준 좌(-1), 현재(0), 우(1)
		for (int y = -1; y <= 1;  y++) {	// 현재 노드 기준 아래(-1), 현재(0), 위(1)
			int x_neighbor = curNode->location.x + x;
			int y_neighbor = curNode->location.y + y;

			if (x_neighbor < 0 || x_neighbor>10)
				continue;
			
			if (y_neighbor < 0 || y_neighbor>10)
				continue;

			Node* neighborNode = created_Map->GetNode(x_neighbor, y_neighbor);	// 위치별 노드 생성
			if (neighborNode == NULL) continue;
			if (neighborNode->NodeInfo == NodeInfo::NotMoveable) continue;

			if (x != 0 && y != 0) {			// (0,y) (x,0) 가 아닌 경우 (대각선 좌표)
				if (neighborNode != NULL && neighborNode->NodeInfo == NodeInfo::NotMoveable)
					continue;
			}

			if (neighborNode == curNode)
				continue;

			neighborList.push_back(neighborNode);
		}
	}

	if (neighborList.empty() == true)
		cout << "neighborList is empty.." << endl;

	return neighborList;
}

int Path::G(Node* startNode, Node* endNode) {
	return G(startNode->location, endNode->location);
}

int Path::G(Point startloc, Point endloc) {
	int x_start2end = abs(endloc.x - startloc.x);
	int y_start2end = abs(endloc.y - startloc.y);

	if (x_start2end > y_start2end)
		return (y_start2end * 14) + (abs(x_start2end - y_start2end) * 10);
	else
		return (x_start2end * 14) + (abs(y_start2end - x_start2end) * 10);
}

int Path::H(Node* startNode, Node* endNode) {
	return H(startNode->location, endNode->location);
}

int Path::H(Point startloc, Point endloc) {
	int x_start2end = abs(endloc.x - startloc.x);
	int y_start2end = abs(endloc.y - startloc.y);

	return (x_start2end + y_start2end) * 10;
}

Node* Path::GetBestF(list<Node*>& openNodeList) {
	if (openNodeList.size() == 0)
		return NULL;

	Node* curNode = openNodeList.back();

	auto startIter = openNodeList.rbegin();
	auto endIter = openNodeList.rend();

	for (; startIter != endIter; startIter++) {
		Node* findNode = *startIter;

		if (findNode->F() < curNode->F()) {
			curNode = findNode;
			continue;
		}
		else if (findNode->F() == curNode->F() && findNode->H < curNode->H) {
			curNode = findNode;
		}
	}
	return curNode;
}