// 7_�Ϻ�������1 - 113 page
#include <iostream>
#include <chrono>

void foo(int a)  {}
void goo(int& a) { a = 100; }
void hoo(int&&){}

/*
template<typename F>
void chronometry(F f, int& arg){
//	f(arg); 
    f(static_cast<int&>(arg));  // int& 타입을 int&로 캐스팅하므로 필요 없는 캐스팅입니다.
                                // 하지만, 있어도 상관없습니다. 컴파일 시에 무시됩니다.
}

template<typename F>
void chronometry(F f, int&& arg){
    f(static_cast<int&&>(arg));
}
*/
// T&& 를 사용하면 모든 타입에 대해서 위 2개 함수를 자동생성할 수 있다.

template<typename F, typename T>
void chronometry(F f, T&& arg){

    // 아래 캐스팅에 대해서 생각해 보세요
    // chronometry 의 2번째 인자로
    // rvalue 를 보내면 (받을때 사용한 lvalue인 arg를) rvalue로 캐스팅
    // lvalue 를 보내면                            lvalue로 캐스팅
//    f(static_cast<T&&>(arg));
    f(std::forward<T>(arg)); // 이 함수가 위와 같은 캐스팅을 합니다. <== perfact forwarding
    
}

int main()
{
    int n = 10;

    chronometry(foo, 10); // T=int        chronometry(함수포인터, int&&)
                          // static_cast<int&&>(arg)

    chronometry(goo, n);  // T=int&        chronometry(함수포인터, int&)
                          // static_cast<int&>(arg)

    chronometry(hoo,10);    
}
