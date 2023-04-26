#include <iostream>
#include <string>
#include <vector>

//왜 move가 중요한가?

template<typename T>
void Swap(T& a, T& b)
{
	// 복사에 의한 swap은 성능이 좋지 않습니다.
//	T tmp = a;
//	a = b;
//	b = tmp;

	// move에 의한 swap이 위 코드보다 빠릅니다.
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move에서 배워야 하는 것
// 1. swap 같은 알고리즘 사용시 복사 대신 move를 사용하면 훨씬 빨라집니다.
// 2. std::string이 아닌 사용자가 만든 타입도 move를 지원하려면 어떻게 해야하는가?
People p1("kim");
People p2 = std::move(p1); 	// 지원하려면?? 필요한 것은

// 3. move 관련 주의 사항




