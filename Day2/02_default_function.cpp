// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 아무일도 하지 않은 인자 없는 생성자가 필요하면

	// 1. 사용자가 직접 구현부 제공
	// Point(){}

	// 2. 컴파일러에게 요청
	// => 컴파일러가 생성자를 직접 구현하므로 모든 것을 알고 있다.
	// => 최적화가 더욱 잘된다.
	Point() = default;	// good
};

int main()
{
	Point p1;
	Point p2(1, 2);

	// 생성자, 소멸자, 복사 생성자등의 특별 함수가 "컴파일러에 의해 생성되고, 널리 알려진 대로 동작" 하는 것을 자명하다고 합니다.
	// trivial 생성자 : 하는 일이 없는 생성자

	std::cout << std::is_trivially_copy_constructible<Point>::value << std::endl;	
}




