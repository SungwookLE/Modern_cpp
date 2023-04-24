// 1_�ʱ�ȭ9. - 63 page 중요!!!!!!!
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);	// Point(int) 생성자 호출

	Point p2(1, 2);	// Point(int, int) 생성자 호출
	Point p3({ 1,2 }); // Point(std::initializer_list<int>0)
	
	Point p4{ 1,2 };	// 핵심.!!
						// 1. Point(std::initializer_list)
						// 2. 1이 없다면 Point(int, int)

	// Point p5(1, 2, 3);  // 이런 생성자 없으니 error
	
	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list)
 	Point p7 = { 1,2,3 }; //ok..

	// 결론: 생성자 인자로 "std::initializer_list"를 사용하면
	//				동일 타입의 값을 가변 길이로 전달 가능합니다.

	// C+11 을 만들 때.. 아래 코드를 되도록하고 싶었습니다.
	// => 그래서 아래 코드에 대한 문법이 필요합니다.
	std::vector<int> v1 = {1,2,3,4,5};
	std::vector<int> v2{1,2,3,4,5};

	// C+11 부터 모든 STL 컨테이너는 배열 처럼 초기화 가능합니다.
	// => 모든 컨테이너에는 "std::initializer_list"를 인자로 가지는 생성자가 있습니다.
	
}


