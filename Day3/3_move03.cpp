#include <iostream>
#include <cstring>
#include <string>

// shallow copy vs deep copy

class Cat
{
	char *name;
	int age;

public:
	Cat(const char *n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	// 클래스가 포인터 멤버가 있다면,
	// 컴파일러가 제공하는 복사생성자를 사용하지 말고 사용자가 복사 생성자를 제공해야합니다.
	// => 깊은 복사로 구현한 복사 생성자
	Cat(const Cat &c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;
}
