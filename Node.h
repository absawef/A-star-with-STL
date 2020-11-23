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

struct NodeInfo {			// ����� ����
	enum Info
	{
		Moveable = 0,		// ���� ����� �̵� ���ɼ� (�̵� ����)
		NotMoveable = 1,	// (�̵� �Ұ���)
		Start = 2,			// ��� ����
		End = 3,			// ��ǥ ����	 
		Final = 7,
	};
};

class Node {

public:
	Node* parent;	// �ش� ����� �θ� ���
	Point location;	// �ش� ����� ��ġ ��ǥ
	NodeInfo::Info NodeInfo;
	int index;
	int G;			// ���� ��ǥ���� ���� ��ǥ������ �Ÿ�
	int H;			// ���� ��ǥ���� ��ǥ ��ǥ������ �Ÿ�

	Node();
	~Node();

	int F() { return G + H; }	 // �޸���ƽ ��
};