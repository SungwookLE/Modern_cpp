// ��������� ����� ������ ���ô�.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자의 정확한 모양을 이해해 봅시다.
	// 방법 1. call by value
	// => 인자를 받을 때 모양이 "Point pt = p2" 인데, 이 때 다시 복사 생성자가 호출됩니다.
	// => 결국, 복사 생성자가 무한히 호출되는 코드 ... 컴파일 에러
	//Point(Point pt){} // Point pt = p2


	// 방법 2. call by non-const lvalue reference
	// 	=> 에러는 아니고, 컴파일 가능.
	//  => 값 타입으로 반환하는 함수의 결과를 받을 수 없다. Point ref = foo(); error
	// Point(Point& pt){}	// "Point& pt = p2"


	// 방법 3. call by const lvalue reference
	Point(const Point& pt): x(pt.x), y(pt.y) {}
	// 결국 사용자가 만들지 않으면 컴파일러가 위 코드를 제공!!


};

Point foo(){
	Point pt(0,0);
	return pt;
}

int main()
{
	Point p1;		
	Point p2(1, 2); 
	Point p3(p2);	// 컴파일러가 만들어주는 복사 생성자 사용.  복사생성자는 유저가 안들어도 컴파일러가 생성해줌
	Point p4 = foo();		// Point p4( foo() ); 이므로 임시객체를 복사생성자로 받으려고 하면 non-const lvalue reference로 생성한 복사생성자로는 컴파일에러 발생

}




