// 3_���۷���1.cpp - 89 page - ���� �߿�!

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point pt(0, 0);

	// 규칙 1. non-const lvalue reference는 lvalue만 가리킬 수 있다.  ==> C+11 부터는 lvalue reference라고 부르는게 맞다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error

	// 규칙 2. const lvalue reference는 lvalue, rvalue를 모두 가리킬 수 있다.
	const Point& r3 = pt;					// ok
	const Point& r4 = Point(0,0) 			// ok, r4 가 소멸될때까지 임시객체의 life-extention됨, 상수성이 있기때문에 read-only 임

	// 규칙 3. rvalue reference는 rvalue만 가리킬 수 있다.
	// => 상수성 없이 임시객체(rvalue)를 가리킬 수 있다.
	// => move, 완벽한 전달을 위해서 필요 .. C++11

	Point&& r5 = pt;				// error, rvalue만 받을 수 있음!
	Point&& r6 = Point(0,0);		// ok

	// const Point&& 는 왜 안 배우나요?그
	// => rvalue만 가리키는데, 사용하는 경우가 없습니다. ...
	// => move 배운 후 설명

}	