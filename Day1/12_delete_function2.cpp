class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 이 코드가 왜 에러가 없나요 ?
				  // 컴파일러가 만들어주는 복사생성자사용
}