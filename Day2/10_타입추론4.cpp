#include <iostream>
//정리!

// 규칙 1. 값 타입으로 받을 떄 , 함수인자의 const, volatile, reference 제거후 T 결정, T의 타입은 결국 a 의 타입
template<typename T> void foo(T a)
{
	
}
// 규칙 2: 참조로 받을 때, 함수 인자의 "reference" 제거 후 T의 타입 결정, T가 결정되면 &를 붙여서 a의 타입을 결정

template<typename T> void goo(T& a)
{
}


int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T : int
	foo(c);  // T : int
	foo(r);  // T : int 
	foo(cr); // T : int

	goo(n);  // T : int          a : int&
	goo(c);  // T : const int    a : const int&
	goo(r);  // T : int          a : int&
	goo(cr); // T : const int    a : const int&
}