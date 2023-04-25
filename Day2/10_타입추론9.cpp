#include <iostream>

int x =0; 
int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4);
	// int ret = foo(1, 3.4); auto는 우변의 참조를 제거하고 결정하므로.. 
	ret = 200; // x 가 수정되는 것은 아님

	// decltype(함수호출식): 함수 호출의 결과로 나오는 타입, 즉, 반환 타입 조사
	decltype(foo(1, 3.4)) ret2 = foo(1, 3.4);
	// int& ret2 = foo(1,3.4)

	// decltype(auto)
	// => auto 자리에 우변을 넣어달라
	// => 우변으로 추론하는데, 규칙은 decltype 규칙으로 !
	// => C+14
	decltype(auto) ret3 = foo(1,3.4); // int& ret3





}