// 7_�Ϻ�������1 - 113 page
#include <iostream>
#include <chrono>
#include "stopwatch.h" 

void f0() {}
void f1(int a) {}
int& f3(int a, double d, int& r) {
    std::cout << a << ", " << d << std::endl;    
    return r;
}


template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg){
    StopWatch sw(true); // 생성자에 시간기록,
                        // 소멸자에서 걸린시간 출력

    return f(std::forward<T>(arg)... ); 
}

int main()
{
    int n = 10;
    int& ret = chronometry(f3, 3, 2.1, n);    
}
