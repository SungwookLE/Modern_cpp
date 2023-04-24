// 1_�ʱ�ȭ10
#include <iostream>
#include <vector>

class Base{
public:
int a,b;
Base(): a{1}, b{2} {}

};

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 }; 
	std::vector<int> v2{ 1,2,3,4,5 };


	//아래 2줄의 차이점은?
	std::vector<int> v3(10, 2); // vector(int, int) 생성자
								// 10개의 요소를 2로 초기화
	std::vector<int> v4{10, 2}; // vector(std::initializer_list)
								// 2개를 10, 2로 초기화


	std::cout << v3.size() << std::endl;
	std::cout << v4.size() << std::endl;

	Base b;
	std::cout << b.a << std::endl;

	// // 아래 코드에서 에러는?
	// std::vector<int> v5 = 10;	 // error
									// *explicit vector(int)""

	std::vector<int> v6 = {10}; // ok
								// "vector(std::initializer_list)"는 explicit 생성자가 아님 
}




