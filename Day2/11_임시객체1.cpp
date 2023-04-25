// 1_임시 객체1
#include <iostream>



class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
	Point pt(1, 2);  // named object
					// 수명: 자신을 선언한 블럭을 벗어날 때 파괴

	Point (1,2); // unnamed object
				// 임시객체(temporary)
				// 수명: 자신을 생성한 문장의 끝
	
	Point(1,2), std::cout << "X" << std::endl;
	

	std::cout << "-------" << std::endl;
}





