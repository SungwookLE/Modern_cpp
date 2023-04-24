#include <cassert> //assert 때문에 필요한 것, static_assert는 헤더 필요없고 C++의 기본 함수임
#include <iostream>

/*
C assert: 실행시간에 값의 유효성 확인
C++ static_assert: 컴파일 시간의 표현식의 유효성 확인, 기계어로 컴파일 될 때 별도 라인 추가 없음 (오버헤드 없음)으로, 적극적으로 많이 활용해주는것이 좋음!!!!
		static_assert는 오픈소스에서 많이 사용되므로 알아두면 좋고, 많이쓰는게 좋음. 컴파일 단계에서의 에러 검출 등..
*/

static_assert(sizeof(int*)==8, "error not 64bit");

void foo(int age)
{
	// 함수 인자는 사용하기 전에 유효성 여부 확인하는 것이 좋습니다.
	
	int* p = new int[age];
	delete[] p;
}
int main()
{
	foo(-10); // 실수로 음수 전달
}