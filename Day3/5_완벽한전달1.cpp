// 7_�Ϻ�������1 - 113 page
#include <iostream>
#include <chrono>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 완벽한 전달(perfect forwarding)
// => 전달받은 인자를 다른 함수에 다시 전달(forwarding) 할 때
// => 어떠한 변화도 없이 완벽하게 전달하는 기술



// 함수의 수행시간을 측정하는 함수
template<typename F, typename T>
void chronometry(F f, T&& arg){
	// <<====== 시간 기록
	f(arg); // 함수 실행 후
	// <======= 수행시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10);  // foo(10);
	chronometry(goo, n);  // foo(10);


	std::cout << n << std::endl;
}
