// 2. 람다표현식 4-1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(){

	std::vector<int> v = {1,2,3,4,5};

	// 아래 코드를 생각해 보세요.
	// sort() 함수는 몇개 생성될까요? 3개
	// => 3개의 sort 함수 생성, 근데 sort 함수가 lambda 를 입력받으면 inline 처리해버리니까 성능상에 차이는 없어요, 람다는 기본적으로 inline 입니다.
	std::sort(v.begin(), v.end(), [](int a, int b){return a <b;});
	std::sort(v.begin(), v.end(), [](int a, int b){return a <b;});
	std::sort(v.begin(), v.end(), [](int a, int b){return a <b;});

	// 동일한 람다 표현식이 여러번 사용되면 auto 변수에 담아서 사용하는 것이 좋습니다.
	auto f = [](int a, int b){return a < b;};
			// class xxx{}; xxx();
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);

	// 이런 경우는 람다 보다도 less{} 를 사용하는 것도 좋습니다.
	std::sort(v.begin(), v.end(), std::less<int>());
	std::sort(v.begin(), v.end(), std::less<int>{});




	return 0;
}