#include <iostream>

// 템플릿은 함수 선언 자체를 호출될때 수행된다.
template<typename T> void foo(T&& arg)
{
}
// 따라서, main 문 안에서 2개의 함수 프로토타입이 생성되므로 2개 함수가 생성되게 된다.
// 확인하는법
// 1. godbold.org에서 확인
// 2. __FUNCSIG__, __PRETTY_FUNCTION__ 으로 출력


int main()
{
	int n = 10;

	foo(n);  // T=int&	T&&=int& &&	foo(int& arg)
	foo(10); // T=int	T&&=int&&	foo(int&& arg)

	//universal reference, forwarding reference
}




