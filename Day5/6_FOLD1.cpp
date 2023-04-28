// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : 가변인자 템플릿의 모든 요소에 이항 연산을 수행 - C++17

// 1. unary right fold : ( pack op ...  ) => ( E1 op (E2 op ( E3 op E4)))
// 2. unary left  fold : ( ...  op pack ) => (((E1 op E2) op E3) op E4)
//
// 3. binary right fold : ( pack op ... init ) => ( E1 op (E2 op ( E3 op ( E4 op init))))
// 4. binary left  fold : ( init ... op pack ) => ((((init op E1) op E2) op E3) op E4)


template<typename ... Types>
int Sum(Types ... args)
{
	int s = 0;
	return s;
}
int main()
{
	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << n << std::endl;
}



