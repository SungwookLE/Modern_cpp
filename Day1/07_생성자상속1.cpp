#include <iostream>


// 7_생성자 상속1
class Base
{
public:
	int value;

	Base()      : value(0) {}
	Base(int n) : value(n) {}
};

Base b1;	//ok
Base b2(5); //ok


class Derived : public Base
{
public:
	// Derived는 멤버 데이터는 추가하지 않고, 멤버 함수정도만 추가하므로
	// 생성자는 필요 없었습니다.
	// 하지만 기반 클래스 멤버를 초기화해야 하므로 C++98 시절에 아래처럼 코딩했습니다.
// Derived() {}
// Derived(int n): Base(n) {}

	// C+11 부터는 "생성자 상속" 문법을 사용하면 됩니다.
	using Base::Base; // 이 한줄이 위와 동일한 역할을 합니다. 보통 상속받은 클래스가 별도의 멤버데이터가 없는 래퍼의 역할을 할때많이 사용됨


	void f1(){}
};

int main()
{
	// 아래 2줄을 생각해 보세요.
	Derived d1;
	Derived d2(5);

	std::cout << d2.value << std::endl;
}
