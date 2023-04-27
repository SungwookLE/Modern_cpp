// 5_����ǥ����5
#include <iostream>
#include <vector>
#include <algorithm>

// ����ǥ���İ� Ÿ��

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
			//class xxx {}; xxx();

	auto f2 = [](int a, int b) { return a + b; };
			//class yyy {}; yyy();

	// 모든 람다 표현식은 다른 다입입니다.
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// 람다 표현식으로 초기화된 변수에 다른 람다는 절대 담을 수 없습니다.
	auto f3 = [](int a, int b){return a+b;};
	f3 = [](int a, int b){return a+b;}; // error, 다른 타입의 객체!!		
}





