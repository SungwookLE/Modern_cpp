#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }		// 1
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }		// 3

int main()
{
	foo(10);

	int&& r = 10;
	
	foo(r);
}







