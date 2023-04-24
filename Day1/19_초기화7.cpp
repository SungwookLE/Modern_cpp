// 1_�ʱ�ȭ6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n1{ 0 };	// direct initialization
	int n2 = { 0 };  // copy initialization
	int n3;				// default initialization
						// => 지역변수는 쓰레기값
	int n4{};		// value initialization
					// => empty brace
					// => int 타입이면 위처럼 {0} 으로 하세요.

	std::cout << n4 << std::endl; // 0

	Point pt{}; 				// 모든 멤버가 모두 기본값으로 초기화 
	std::cout << pt.x << std::endl;
}

template<typename T> 
void foo(T a){
	T s{0}; // T가 0으로 초기화 될 수 있다는 보장이 없다.
	T s{}; // 이렇게 써라
}


