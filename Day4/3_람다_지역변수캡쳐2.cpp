#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 
	
	// mutable 람다 표현식: operator() 연산자를 const 함수로 하지 말라는 것!
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; 

	f1(0); // 이순간 v1 = 100 을 실행하지만, 복사본 v1이 변경되는 것 입니다.
	std::cout << v1 << std::endl; // 10


	// 람다 표현식이 만드는 객체의 크기 ??
	// => 캡쳐한 변수를 멤버 데이터에 보관하는 거,
	// => int 2개 멤버 데이터가 있으므로 8
	std::cout << sizeof(f1) << std::endl; // 


	// 위 f1의 정확한 원리를 생각해 봅시다. => 꼭 이해해 두세요.
	class CompilerGeneratedName{
		int v1; // 지역변수를 캡쳐하면 컴파일러가 만드는 클래스에 이렇게 멤버 데이터가 추가됩니다.
		int v2;
		public:
			CompilerGeneratedName(int a, int b): v1(a), v2(b) {}
			inline auto operator()(int a) // const <= const 를 주석처리한게 mutable 키워드입니다.
			{
				v1 = 100;				// () 연산자 함수가 상수함수라면 error 입니다. 상수멤버함수는 멤버의 데이터를 변경할수없음 read 함수여야함
				return a + v1 + v2;
			}
	};

	auto f1 = CompilerGeneratedName(v1, v2);
}





