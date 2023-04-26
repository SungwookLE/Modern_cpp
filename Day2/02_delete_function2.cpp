class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

// 	void foo(){
// 		Point p1;
// 		Point p2(p1); // 복사 생성자가 private에 있어도 ok
// 						// 단, 복사생성자가 선언만 있으면 링크 에러
// 	}

// 	// 컴파일러가 복사 생성자를 만들 수 없게 하는 방법
// 	// 1. C+11 이전에 사용하던 기술
// 	// => private 영역에 선언부만 제공합니다.
// 	// 	사용할 수 없게 하기 위해 의도적으로 구현 생략
// private:
// 	Point(const Point& p);


	// 2. C+11 이후 "함수 삭제" 문법 사용
	Point(const Point&) = delete;
};

int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 이 코드가 왜 에러가 없나요 ?
				  // => 컴파일러가 만들어주는 복사 생성자 사용
}