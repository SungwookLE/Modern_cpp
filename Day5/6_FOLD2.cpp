#include <iostream>
#include <vector>

std::vector<int> v;

template<typename ... Types>
void foo(Types ... args)
{

}

int main()
{
	foo(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



