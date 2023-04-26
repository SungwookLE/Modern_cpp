// 7_�Ϻ�������1 - 113 page
#include <iostream>
#include <chrono>

void hoo(int&&){}

template<typename F>
void chronometry(F f, int& arg){
	// <<====== 시간 기록
	f(arg); // 함수 실행 후
	// <======= 수행시간 출력
}

// main                    chronometry                hoo(int&&)
// hoo(10) =========================================> ok.            
// chronometry(10) ======> int&& arg=10으로 받음 =====> hoo(arg): error

template<typename F>
void chronometry(F f, int&& arg){
    // 이 함수에 10이 전달되면 "int&& arg=10"이 되는데 ..
    // 원래 인자는 10이라는 rvalue 인데, 받을 때 사용한 arg는 lvalue

//	f(arg); // error. hoo(init&) 찾음.

    f(static_cast<int&&>(arg)); // ok
}

int main()
{
    hoo(10);    
    chronometry(hoo,10);    
}
