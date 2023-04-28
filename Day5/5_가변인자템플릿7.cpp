#include <iostream>

// recursive?

// 1번째 인자는 독립된 변수 명으로 받으세요.

void foo(){} // 재귀의 종료를 위해

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;
//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()

	// C++17 부터는 아래처럼 하세요. (constexpr 이 17부터임)
	if constexpr (sizeof...(args) > 0)
		foo(args...);

}

int main()
{
	foo(1, 3.4, 'A'); 
}





