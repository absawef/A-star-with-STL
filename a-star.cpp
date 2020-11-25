#include "MyMap.h"
#include "Node.h"
#include "Path.h"
#include <iostream>

using namespace std;

int main() {
	int mapRow = 10;				// 맵의 크기
	int mapCol = 10;		
	
	Point startloc = Point::Point(0,0);		// 시작 지점과 목표 지점
	Point endloc = Point::Point(9,9);	
	
	MyMap Map;					// 맵 정의
	Map.setRowCol(mapRow,mapCol);			// 맵 크기 할당
	Map.CreateMap(startloc, endloc);		// 시작 지점과 종료 지점 전달 & 최종 맵 생성

	Map.ShowMap(list<Node*>());				// 전
	cout << "==============================" << endl;
	
	Path path(&Map);					// 맵에 대한 경로 생성
	
	auto nodeList = path.DoFindPath(startloc, endloc);	// 후
	cout << endl;
	Map.ShowMap(list<Node*>());

	return 0;
}
