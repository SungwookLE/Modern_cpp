#include <iostream>

// 함수 인자로 auto를 사용할 수는 없습니다.
// void foo(auto n) {}

// void foo(auto n) {} 

int main()
{

//	foo(1);
//	foo(3.4);	

	// generic lambda
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2);


	// generic lambda : 인자로 auto를 사용하는 람다, C+14 부터 지원
	auto add = [](auto a, auto b){return a+b;};

	std::cout << add(1,2) << std::endl;
	std::cout << add(1.1,2.1) << std::endl;
	std::cout << add(1,2.1) << std::endl;
	std::cout << add(1.1,2) << std::endl;
}

// generic 람다 원리
// 핵심 : 2개의 인자가 서로 다른 템플릿
class CompilerGeneratedName{
	public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const{

	}
};