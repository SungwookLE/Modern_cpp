#include <iostream>
#include <type_traits>

int main()
{
	remove_all_pointer<int***>::type n;
}
