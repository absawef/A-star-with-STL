#include "Node.h"

Node::Node() {		// 노드 초기화
	parent = NULL;
	index = 0;
	NodeInfo = NodeInfo::Moveable ;
	G = 0;
	H = 0;
}

Node::~Node() { }