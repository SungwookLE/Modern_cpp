// 1. decltype 언제 사용하는지 알아 두세요.
//	=> 아래와 같은 템플릿에서 많이 사용!

// 2. 하지만, 아래 코드는 에러...
#include <iostream>

template<typename T1, typename T2>
decltype(a*b) Mul(T1 a, T2 b) // error: a, b를 선언전에 사용
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;

	// a = 20; // error. 변수를 선언 전에 사용
	// int a= 0;
	// a = 10; // ok. 변수를 선언후에 사용



}

