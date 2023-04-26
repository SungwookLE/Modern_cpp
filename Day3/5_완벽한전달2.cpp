// 7_�Ϻ�������1 - 113 page
#include <iostream>
#include <chrono>

void foo(int a)  {}
void goo(int& a) { a = 100; }


// 핵심 1. int&, int&& 버전으로 2개를 제공해야 한다.
//  2. 그런데 아래 코드에는 한가지 문제가 있다.


template<typename F>
void chronometry(F f, int& arg){
	// <<====== 시간 기록
	f(arg); // 함수 실행 후
	// <======= 수행시간 출력
}

template<typename F>
void chronometry(F f, int&& arg){
	// <<====== 시간 기록
	f(arg); // 함수 실행 후
	// <======= 수행시간 출력
}

void hoo(int&&){}

int main()
{
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n);  

    hoo(10);    // ok...잘된다..
    chronometry(hoo,10);    // 잘되어야하는데! 에러이다. 왜?
                            // 다음소스에서 해결

	std::cout << n << std::endl;
}
