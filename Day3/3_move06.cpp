#include <iostream>
#include <cstring>

// 클래스 안에 포인터 멤버가 있고, 자원할당하는 코드가 있다면,
// C+98 시절: 복사 생성자, 대입연산자를 만들어야 합니다.
// C+11 이후: 이동 생성자, 이동 대입연산자도 만드는 것이 좋습니다.




class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
		std::cout << "copy ctor" << std::endl;
	}
	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "move ctor" << std::endl;
	}

	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		age = c.age;
		delete[] name;
		
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
		std::cout << "copy assign(=) " << std::endl;

		return *this;
	}

	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		age = c.age;
		delete[] name;

		name = c.name;
		c.name = nullptr;	

		std::cout << "move assign(=) " << std::endl;
		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;   					// 복사 생성자
	Cat c3 = std::move(c1);			// move 생성자

	c3 = c2;						// 대입 연산자 호출
	c3 = std::move(c2);				// move 이동 대입연산자 호출
}




