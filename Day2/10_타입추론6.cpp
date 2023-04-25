#include <iostream>


// decltype 타입 추론을 위한 참고 소스
int x = 0;

int  f1() { return x; } // x의 값인 "0"을 반환한 것
int& f2() { return x; } // x의 값이 아닌 별명을 반환한 것

int main()
{
	f1() = 20; //  error. "0 = 20"
	f2() = 20; // ok. "x의 별명 = 20"

	// 핵심: 함수가 참조를 반환하면
	// 함수 호출을 "=" 의 왼쪽에 올 수 있습니다.

}