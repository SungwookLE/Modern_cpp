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
	virtual void foo()      override {} 
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

int main()
{
}