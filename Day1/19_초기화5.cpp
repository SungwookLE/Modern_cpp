// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성자: 직접 초기화만 가능하고,
	//					복사 초기화는 사용할 수 없다.
	//					C+98 문법

	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
	// 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10); // C++98 스타일의 direct 초기화
	Vector v2 = 10;  // c++98 스타일의 copy 초기화
	Vector v3{ 10 }; // c+11 스타일의 direct 초기화
	Vector v4 = { 10 }; // C+11 스타일의 copy 초기화

	//----------------
	foo(10); // "Vector v = 10" 의 의미 입니다.
			 // => 함수의 인자 전달은 복사 초기화 과정

}







