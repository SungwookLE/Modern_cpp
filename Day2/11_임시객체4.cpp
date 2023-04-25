// 3_�ӽð�ü1 - 77 page
#include <iostream>

/*
void f1(Point  pt) {} // call by value : 복사본 생성
void f2(Point& pt) {} // call by reference: 복사본 생성 안됨
*/

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

void f1(Point pt) {}
void f2(Point &pt) {}

Point pt(1, 2);

Point foo() // return by value : 임시객체를 반환
{
	return pt; // pt가 반환되지 않고, pt의 복사본이 반환
}

Point &goo() // return by reference
{
	return pt; // pt가 반환되지 않고, pt의 참조  반환
}

int main()
{
	// foo().x = 10;
	goo().x = 10;
}

// 단, 지역변수는 절대 참조 반환하면 안됩니다.
Point &hoo()
{
	Point pt(1, 2); // 지역변수
	return pt;		// 버그.. 절대 사용하면 안됩니다. 전역변수이거나, 멤버변수등 함수 호출뒤에도 파괴되지 않는 보장이 있어야합니다.
}
