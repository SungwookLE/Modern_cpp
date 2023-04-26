// 아래 코드가 왜 에러인지 생각해 보세요?

/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error. data는 int 타입이므로 *data  할수없다.
	}
};
*/

template <typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10; // 당장에 에러를 만들어내진 않음 (컴파일 할 때 왜냐면 템플릿은 선언된 멤버만 실제 인스턴스화됨) 
	}
};


int main()
{
	// 지연된 인스턴스화(C++98 문법)
	// => 클래스 템플릿의 멤버 함수 중에서 사용된 것만 실제 인스턴스화("템플릿=>C++클래스")에 포함된다..
	A<int> a;
	a.foo(); // 사용한 멤버 함수만. foo함수도 템플릿 => C++ 클래스 만들 때 포함됩니다. => 에러가 됨
}