// 4_type_traits3 - 210 page
#include <iostream>

// 표준  traits 를 사용하려면
#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. 조사하려면
	bool b1 = std::is_pointer<T>::value;

	// 2. 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1;
}

int main()
{
	int n = 0;
	foo(&n);
}
