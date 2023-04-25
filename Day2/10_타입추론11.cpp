#include <iostream>

// C+11 후위 반환 표기법
// => 함수의 반환 타입을 함수 () 뒤쪽에 표기하는 문법
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a*b)
{
	return a * b;
}

// 아래 처럼 해도 되긴 합니다.
// 단,
// 1. return 문장이 한 개 일때만 가능합니다.
// 2. auto 추론을 사용하게 됩니다.
// 		a*b의 결과가 int& 라도 리턴 타입은 int 입니다.
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b) 
{
	return a * b;
}

// 아래 처럼하면 auto 추론이 아닌 decltype 으로 추론
// 단, return 문이 2개 이상이면 에러
template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b) 
{
	return a * b;
}





int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

