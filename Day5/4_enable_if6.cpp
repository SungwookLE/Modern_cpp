
#include <iostream>
#include <type_traits>

// C++ 에서 enable_if 는 라이브러리 설계의 핵심 기술이 되었습니다.

// 그래서 C++20 에서
// enable_if 를 더욱 발전시킨 "Concept" 이 도입됩니다.

/*
template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
    std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
    std::cout << v << std::endl;
}
*/

// C++20 부터는 실제로는 아래처럼 합니다.
// => C++20 부터는 함수 인자로 "auto"라고만 적어도 template 입니다.

// void foo(auto a) : 템플릿
// void foo(pointer auto a): pointer 조건을 만족하는 것만 가능한 템플릿

template<typename T>
concept pointer = std::is_pointer_v<T>;

void printv(pointer auto v){
	std::cout << v << " : " << *v << std::endl;
}

void printv(auto v){
	std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n); // <!!
	printv(&n);
}

