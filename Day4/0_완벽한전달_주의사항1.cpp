
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)   // std::nullptr_t arg = nullptr;
{
	f(std::forward<T>(arg));
}

// 인자로 포인터(주소)를 요구!!
void foo(int* p) {}

int main()
{
	int n=0;
	foo(0); // ok , 0 전달 가능 nullptr 주소를 준거지
	//chronometry(foo, 0); // error, 0을 주니까 타입추론할때 int로 인지되면서, rvalue 레퍼런스가 되면서 에러가 발생
	chronometry(foo, nullptr); // std::nullptr_t arg = nullptr; 이니까, 에러없음
}









