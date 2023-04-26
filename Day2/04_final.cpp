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
	// final : 더이상 재정의 할 수 없다는 의미.
	virtual void foo()      override final {} 
	virtual void goo(int a) override final {}
	virtual void hoo()      override final {}
};

class Derived2 : public Derived{

	public:
	virtual void foo() 	override{}


}

int main()
{
}