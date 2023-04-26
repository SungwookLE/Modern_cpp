// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// 가상함수 재정의시 실수 (오타)
	// => 실수를 했지만 에러가 아니다.
	// => 새로운 가상함수를 만들었다고 컴파일러가 생각
	// => 버그의 원리

	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
};

class Derived2 : public Base
{
public:
	// C+11 부터는 가상함수를 재정의 할 때 "override" 붙이는 것을 권장합니다.
	virtual void fooo() 		override{}
	virtual void goo(double a) 	override{}
	virtual void hoo() const  	override{}
};



int main()
{
}