#include <iostream>

template<typename ... Types> void foo(Types ... args)
{

}

int main()
{
	foo(1, 3.4, 'A');
	foo(1, 2, 3);
}