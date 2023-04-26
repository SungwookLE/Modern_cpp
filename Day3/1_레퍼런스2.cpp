#include <iostream>

// 90 page, 함수 오버로딩 (인자만 다르게)
void foo(int& a)       { std::cout << "int&" << std::endl; }  // lvalue reference 1
void foo(const int& a) { std::cout << "const int&" << std::endl; } // const lvalue reference 2
void foo(int&& a)      { std::cout << "int&&" << std::endl; } // rvalue reference 3

int main()
{
	int n = 10;
	foo(n);  // 1번과 2번 모두 가능하지만 1번이 우선권이 있음, 1번 없으면 2번 호출
	foo(10); // 2번과 3번이 모두 가능하지만 3번이 우선권이 있음, 3번 없으면 2번 호출
}







