#include <iostream>

// 규칙 2. 함수 인자가 참조(T&) 타입 일 때
// => 함수, 인자가 가진 reference 속성만 제거하는 타입 결정
// 		const, volatile 은 유지


template<typename T> void foo(T& a)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T = int, a = int&
	foo(c);  // T = const int, a = const int&
	foo(r);  // T = int, a = int&
	foo(cr); // T = const int , a = const int&
}