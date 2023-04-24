// 1_초기화9 - 62page
#include <iostream>
#include <initializer_list> // 핵심

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// std::initializer_list<int>
	// => 모든 초기값을 메모리에 만들고 (위치는 표준에서 정의 안됨)
	// => 대부분 컴파일러는 스택에 할당 (읽기만 가능)
	// => s 자체는 포인터 2개 또는 "포인트+길이"

	std::initializer_list<int> s = { 1,2,3,4,5 };

	auto p1 = s.begin();
	auto p2 = s.end();

	// *p1 = 10; //error. 읽기 전용

	// 왜 만들었나요?
	// => 함수 인자로 사용하기 위해!
	// => foo 에는 int 타입의 값을 "가변 길이로 전달 가능"

	foo(s);
	foo({1,2,3});// 벡터도 이런게 가능했었는데, 벡터는 동적할당을 하니까 무거운 컨테이너임. linked list같은 경우는 메모리가 연속적임을 보장하지 않으니까 불편했고,
	foo({1,2,3,4,5}); // 가변 길이가 가능한 배열로 생각 하세요.

}


