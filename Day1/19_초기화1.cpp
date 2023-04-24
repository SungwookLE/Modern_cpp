// �ʱ�ȭ - 55 page
#include <iostream>

int x = 10;

// 핵심: 클래스(구조체)의 멤버 데이터를 직접 초기화 가능합니다.
// => "field initialization" 문법

class Test
{
	// 필드 초기화의 원리
	// => "0" 등의 리터럴로 초기화 하는 것은 좋은데,
	// => "++x" 같은 표기법은 절대 사용하지 마세요..
	
	int value1 = 0;						// 여기 있는 초기값을 보고
	int value2 = ++x;					// 아래 생성자가 변경됩니다.
public:									// 컴파일러가 변경한 코드
	Test() {}								// Test(): value1(0), value2(++x){}
	Test(int n) : value2(n) {} 				// Test(int n): value2(n), value1(0) {}
};

int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // 예측해보세요.? : 11
}