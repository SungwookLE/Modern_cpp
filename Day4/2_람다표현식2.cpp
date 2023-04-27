// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 위 한줄의 코드를 컴파일러는 아래 코드로 변경합니다.
	class CompilerGeneratoredName{
		public:
			inline auto operator()(int a, int b) const
			{
				return a<b;
			}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratoredName());

	// 람다표현식은 : 컴파일러가 만든 함수객체를 "임시객체" 형태로 생성하는 코드.
	
}






