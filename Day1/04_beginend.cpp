// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>
#include <queue>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	//int v[5] = { 1,2,3,4,5 };


	// 1. 반복자의 정확한 타입을 알아 두세요.
	// => 그런데, 정확한 타입을 사용하면, 컨테이너 교체시 아래 코드도 수정되어야 합니다.

	// std::vector<int>::iterator p1 = v.begin();
	// std::vector<int>::iterator p2 = v.end();

	// 2. 되도록이면 auto를 사용하세요.
	// auto p1 = v.begin(); // v가 raw array라면 error

	// 3. 일반 함수 begin 을 사용하면 유연성이 좋습니다.
	auto p1 = std::begin(v); // v 가 raw array 라도 가능

	auto sz = v.size(); // raw array 라면 error
	// =>auto sz = std::size(v); // raw array 라도 ok
	std::cout << sz << std::endl;

}