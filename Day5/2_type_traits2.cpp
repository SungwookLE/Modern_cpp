#include <iostream>
#include <type_traits>

template<typename T> void foo(const T& a)
{
	if ( ? )
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}