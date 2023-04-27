#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

    // [v1,   v2]   : capture by value
    // [&v1, &v2]   : capture by reference

    // =>  reference 캡쳐
	auto f1 = [&v1, &v2](int a){ v1 = 100; return a + v1 + v2; }; 

    f1(0); // v1=100에서 v1은 main의 지역변수를 변경

	std::cout << v1 << std::endl; 

	class CompilerGeneratedName{
		int& v1; 
		int& v2;
		public:
			CompilerGeneratedName(int& a, int& b): v1(a), v2(b) {}
			inline auto operator()(int a) const   // const 특성을 유지할수잇는게 reference는  main의 지역변수를 가리키고 main의 지역변수를 바꾼ㄴ다는거지 멤버 데이터를 바꾼다는 의미는 아니니까 const 맞음
			{
				v1 = 100;				
				return a + v1 + v2;
			}
	};

	auto f1 = CompilerGeneratedName(v1, v2);
}





