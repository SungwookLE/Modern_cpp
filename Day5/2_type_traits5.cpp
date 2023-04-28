
#include <iostream>
#include <type_traits>

template<typename T>
void printv(const T& v)
{
	if constexpr ( std::is_pointer_v<T> )  //<= constexpr을 붙임으로서 컴파일시간에 포인터가 아니면 아래줄이 실행되지 않게하여 컴파일 에러를 없애버림
        std::cout << v << " : " << *v << std::endl;
	else
        std::cout << v << std::endl;
}
int main()
{
	int n = 10;
	double d = 3.4;

	printv(n); // <!!
	printv(&n);
}

