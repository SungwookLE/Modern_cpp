// 1_�ʱ�ȭ11 - 65 page..
// aggregate initialization
// => 생성자가 없어도 중괄호로 초기화 가능한 타입
// => C 배열, 구조체 등 ...

struct Point// 모든 멤버가 public 이라면 class보다 구조체를 사용하는 경우가 종종 있습니다.
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

    void foo(){}    // 멤버 함수가 있을 때 - aggregate 타입입니다.
    //virtual void goo() {} // 가상함수가 있으면 - aggregate 타입 아님

    //Point() {}  // 사용자가 만든 생성자가 있을 때
                // => aggregate 타입 아닙니다.

    Point() = default; // default 생성자는 aggregate 타입
                        // C+20 부터는 "aggregate 타입" 아닙니다.
};



int main()
{
	Point p1;	
	Point p2 = {1, 2};
}