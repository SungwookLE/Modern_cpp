#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }		// 1
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }		// 3

int main()
{
	foo(10);			// 3

	int&& r = 10;
	
	foo(r);				// 1
						// int&& r = 10 에서
						// "10은 rvalue 지만 r은 lvalue" 입니다.
						// 이름이 있고 단일식을 벗어나서 사용가능
	foo(static_cast<int&&>(r));	// foo(int&&) 호출

			// static_cast<타입&&>	: 타입 캐스팅이 아닌, value 속성을 변경하는 캐스팅, lvalue => rvalue로 캐스팅
			
	
	// 타입과 value 속성을 혼돈하지 마세요.
	int n = 0;

	//		타입	value속성
	// n	int		lvalue
	// n+1 	int		rvalue
	// 10	int		rvalue
	// r	int&&	lvalue

	// foo(int&) : 인자로 int& 타입을 받겠다는 것이 아니라
	//				인자로 lvalue를 받겠다는 것
	// foo(int&&) :	인자로 rvalue를 받겠다는 것

}







