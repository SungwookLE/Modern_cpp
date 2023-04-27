// 6_����_��������ĸ��1 - 146
#include <iostream>

int g = 10;

int main()
{

	// 1. 람다표현식에서 전역변수
	// => ok... 람다표현식에서 전역변수 사용가능.
	auto f1 = [](int a) { return a + g; };
			  // class xxx{ operator()(int) { a+g;}}; xxx();

	// 2. 람다표현식에서 main 지역변수 사용
	// => 기본적으로 접근할 수 없음. 접근하려면 캡처해야한다.
	int v1 = 10, v2 = 10;
	// auto f2 = [](int a){return a+v1+v2;};	// error
	auto f3 = [v1, v2](int a){return a+v1+v2;}; // ok

	auto f4 = [v1, v2](int a){ v1 = 100; return a; }; // error. 변경 안됨

	auto f5 = [v1, v2](int a) mutable {v1=100; return a;}; // mutable 키워드 붙이면 가능함 


}





