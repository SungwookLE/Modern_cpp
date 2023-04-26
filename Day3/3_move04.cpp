#include <iostream>
#include <cstring>
#include <string>

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

	Cat(const Cat &c) : age(c.age) // deep copy
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

    // 임시객체를 위한 복사 생성자를 추가로 만들자는 것!!!
    // 임시객체는 rvalue 이므로 인자를 "Cat&&"
    Cat(Cat &&c) : age(c.age), name(c.name) // 포인터 주소만 뻇어오고, 원래 임시객체에 주소는 해제시켜!
	{
		// 아래 코드를 수행하기 위해서
        // 임시객체도 상수성 없이 가리킬 수 있어야 합니다.
        c.name = nullptr;
	}


};

Cat foo(){
    Cat c("yaong", 3);
    return c;
}

int main()
{
	Cat c = foo(); // 이순간 메모리 상황을 생각해 보세요. 
                   // (내생각) 임시객체를 받은 것이네요. 임시객체를 받아다 쳐도 deep copy 생성자 구현하면 문제 없는 것 아닌감?
                   // 아 근데 임시객체는 곧 죽을 녀석이니까 복사생성자와 같이 비용이 크게 할 필요없이 move 하자고?

}
