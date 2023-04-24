// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

template<typename T>
class reverse_view{
	T& c;
	public:
	reverse_view(T& c): c(c) {}
	auto begin() {return c.rbegin();}
	auto end()	{return c.rend();}
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++ 11 에서 도입된 새로운 for문 - range for 라고 합니다.
	// for(int e: v) // 컨테이너 또는 배열
	for (auto e: v){
		std::cout << e << ", " ;
	}	

	reverse_view<std::vector<int>> rv(v);
	for(auto e : reverse_view<std::vector<int>> (v)){
		std::cout << e << ", " ;
	}

}















