#include <iostream>

class Object
{
public:
	Object() {}
	Object(const Object&)     { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept { std::cout << "move" << std::endl; }
};

// std::move 원리(구현)

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o2);	
}



