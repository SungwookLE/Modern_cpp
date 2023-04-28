#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	printv(args...);

}


int main()
{
	foo(1, 2, 3);
}

