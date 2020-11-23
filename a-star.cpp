#include "MyMap.h"
#include "Node.h"
#include "Path.h"
#include <iostream>

using namespace std;

int main() {
	int mapRow = 10;
	int mapCol = 10;
	
	MyMap Map;								// �� ����
	Map.setRowCol(mapRow,mapCol);

	Point startloc = Point::Point(0,0);		// ���� ������ ��ǥ ����
	Point endloc = Point::Point(9,9);	

	Map.CreateMap(startloc, endloc);		// �� ����

	Path path(&Map);						// �ʿ� ���� ��� ����

	Map.ShowMap(list<Node*>());							// ��
	cout << "==============================" << endl;

	auto nodeList = path.DoFindPath(startloc, endloc);	// ��
	cout << endl;
	Map.ShowMap(list<Node*>());

	return 0;
}