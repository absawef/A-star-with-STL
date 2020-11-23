#include "MyMap.h"
#include "Node.h"
#include "Path.h"
#include <iostream>

using namespace std;

int main() {
	int mapRow = 10;
	int mapCol = 10;
	
	MyMap Map;								// 맵 정의
	Map.setRowCol(mapRow,mapCol);

	Point startloc = Point::Point(0,0);		// 시작 지점과 목표 지점
	Point endloc = Point::Point(9,9);	

	Map.CreateMap(startloc, endloc);		// 맵 생성

	Path path(&Map);						// 맵에 대한 경로 생성

	Map.ShowMap(list<Node*>());							// 전
	cout << "==============================" << endl;

	auto nodeList = path.DoFindPath(startloc, endloc);	// 후
	cout << endl;
	Map.ShowMap(list<Node*>());

	return 0;
}