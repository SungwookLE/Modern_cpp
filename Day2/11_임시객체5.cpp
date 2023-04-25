#include <iostream>
// 85 page
struct Base
{
	Base() {std::cout << "Base생성" << std::endl;}
	int value = 10; 
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	std::cout << "시작" << std::endl;
	Derived d;
	std::cout << d.value << std::endl;  // 20
	std::cout << static_cast<Base&>(d).value << std::endl; // 10, 참조(REF)로 Base를 만들게
	std::cout << static_cast<Base>(d).value << std::endl; // 10, 임시객체로 Base가 만들어지고, d로 초기화


	static_cast<Base&>(d).value = 30; // ok
	// static_cast<Base>(d).value =10; // error, 값 캐스팅은 임시객체를 생성한것
	
	std::cout << static_cast<Base&>(d).value << std::endl; // 30, Base의 value가 변한것

}

// Base 안에 "복사 생성자", "소멸자" 만들어서 로깅해보시면 임시객체 생성되는 결과 확인 가능함
