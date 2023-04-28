#include <iostream>


template<typename T>
int foo(T a)  { std::cout << "T" << std::endl; return 0; }

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); 
}