// 3_함수객체7 - 136 page소스
#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준 sort()는 모든 인자가 템플릿 입니다.
	// => 사용자가 사용하는 코드를 보고 실제 sort 함수가 생성된다는 의미

	// 1. 비교 정책으로 일반함수 사용시

	std::sort(x, x + 10, cmp1); 
	std::sort(x, x + 10, cmp2); 

	// 2. 비교정책으로 함수객체 사용시

	Less    f1;
	Greater f2;
	std::sort(x, x + 10, f1); 
	std::sort(x, x + 10, f2); 
}









