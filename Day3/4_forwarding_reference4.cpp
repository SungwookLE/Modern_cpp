struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
