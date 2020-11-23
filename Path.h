#pragma once
#include "MyMap.h"
#include "Node.h"

using namespace std;

class Path {
private:
	MyMap* created_Map;

public:
	Path(MyMap* Map);
	~Path();

	list<Node*> DoFindPath(Point Startloc, Point Endloc);
	
private:
	list<Node*> Astar(Node* endNode);
	list<Node*> GetNeighborList(Node* curNode);
	Node* FindPath(Point startloc, Point endloc);
	
	int G(Node* startNode, Node* endNode);
	int G(Point startloc, Point endloc);

	int H(Node* startNode, Node* endNode);
	int H(Point startloc, Point endloc);

	Node* GetBestF(list<Node*>& openNodeList);
};