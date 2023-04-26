struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};


// 방법1. call by value
// => 특징: 복사본 생성, 복사본의 구조체가 큰경우 복사에 의한 오버헤드가 발생함
// void foo(Point pt){}


// 방법2. call by const-reference
// => 특징: 복사본은 없지만, "상수성"이 추가된다.
// => foo 안에서 읽기만 할 것이라면 좋은 코드 ...
void foo(const Point& pt){}

// 복사본도 없고, 상수성 추가도 없이 받을 수는 없을까?
// => C++98에서는 만들 수 없다!
// => C+11 부터는 가능

// 방법3. 2개의 함수 제공: 함수 오버로딩
void foo(Point& pt){}
void foo(Point&& pt){}

// 방법4. forwarding reference(T&&) 를 사용하면
//		방법3의 2개 함수를 자동생성할 수 있다.
template<typename T>
void foo(T&& pt){}

int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue와 rvalue(임시객체)를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
