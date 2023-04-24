#include <map>
#include <string>

using namespace std::literals;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

void f1(int n) {}
void f2(Point pt) {}

int main()
{
	f1(3); // 결국 int n = 3 의 의미
		   // 즉, "함수의 인자 전달은 복사 초기화" 과정입니다.


	f1({3}); // C+11 부터 가능 "int n = {3}"
	f2({1, 2}); // Point pt = {1,2}
	std::map<std::string, std::string>m;

	std::pair<std::string, std::string> p("mon", "월요일");
	m.insert(p);

	m.insert( {"tue", "화요일"}) ; // ok...
}

Point f3() 
{ 
	// return Point(1, 2); 
	// return Point(1,2);
	return {1,2}; // ok.. 리턴 타입이 Point인지 컴파일러가 알고 있으므로..
}
