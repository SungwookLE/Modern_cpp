// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// 모든 멤버를 꺼내고 싶다...until C+14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// C+17 에서는 아래 처럼 할 수 있습니다.
	// => "structure binding" 이라는 문법
	auto [a1, a2, a3] =p3d; //auto a1 = p3d.x
							//auto a2 = p3d.y
							//auto a3 = p3d.z
	
	//int [b1,b2,b3] = p3d; // error. auto 만 가능
	//auto [c1,c2] = p3d; // error. 갯수가 동일해야 합니다.

	// 배열도 가능합니다.
	int arr[3] = {1,2,3};
	auto [d1,d2,d3] = arr;


	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "������";

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p); // m["tue"] = "화요일"

	// -------------------
	// map의 모든 요소 접근하기
	// 1. C+11 스타일
	for (auto &p: m){
		// p는 pair 입니다.
		auto key = p.first;
		auto value = p.second;
	}

	// 2. C+17 스타일 - 아래 코드는 위와 동일합니다.
	for (auto[key, value] : m){

	}

}

