
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};


// 핵심: Point에 디폴트 생성자가 없습니다.
// Point pt; //error
class Rect
{
	Point pt; // ?
public:
	// 사용자 코드 				// 컴파일러가 변경한 코드
	// Rect() {}				  // Rect(): Point() {}

	// C+98 시절의 해결책
	// => 사용자가 명시적으로 멤버의 생성자를 호출
	Rect(): pt(0,0) {}
};

//C+11 부터는 아래처럼 해도됨
class Rect2
{
	Point pt{0,0}; 
	// Point pt2(0,0); // error, 이 경우는 {}만 됩니다. 컴파일러가 pt2를 멤버 함수로 해석
public:
	// 사용자 코드 				// 컴파일러가 변경한 코드
	// Rect() {}				  // Rect(): Point() {}
};
int main()
{
	Rect r1;
}

