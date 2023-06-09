// 2_람다표현식3-1.cpp
struct Point{
	int x, y;
	Point(int a, int b): x(a), y(b){}
};

int main(){
	// 아래 한줄을 완벽하게 이해해 봅시다.
	Point pt = Point(1,2);

	// C++98:
	// => 1. 임시객체를 생성하고
	//	  2. 컴파일러가 자동으로 만들어준 복사생성자를 이용해 pt에 복사
	// 
	// => 대부분의 컴파일러는 이 코드를 아래 코드로 최적화
	// 	  Point pt(1,2)

	// C++11:
	// => 1. 임시객체를 생성하고
	//    2. 컴파일러가 자동으로 만들어준 move 생성자를 사용해서 pt 생성
	// => 대부분의 컴파일러는 이 코드를 아래 코드로 최적화
	// 	  Point pt(1,2)

	// C++17: 모든 컴파일러는 Point pt(1,2)로 해야 한다.
	// => 즉, 최적화로 했던 기술을 문법화합니다.

	// ---------------------------------------
	// 아래 2줄을 비교해 봅시다.
	Point p1 = Point(1,2);
			// 그냥 아래처럼 생성한 것. 오버헤드 없음
			// Point p1(1,2)
	Point&& p2 = Point(1,2);
			// Point(1,2) 를 만들고 p2가 가리키는 것
			// 참조는 결국 내부적으로는 포인터 !!!
		
	// godbolt 에서 아래 2줄을 비교해 보세요.
	int n1 = p1.x;
	int n2 = p2.x;
}

// godbolt.org 확인법 (빌드 플래그)
// -std=c++98, c++11, c++14, c++17
// -fno-elide-constructors
