#include "Node.h"

Node::Node() {		// ��� �ʱ�ȭ
	parent = NULL;
	index = 0;
	NodeInfo = NodeInfo::Moveable ;
	G = 0;
	H = 0;
}

Node::~Node() { }