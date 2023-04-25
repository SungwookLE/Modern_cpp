// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
	// T a  = 10 으로 생각하시면 됩니다.
	auto a = 10; // 결국 auto와 템플릿 추론은 동일합니다

	// 위 코드에서 "auto"가 무슨 타입으로 추론되었는지 확인은 어렵습니다. 그런데, 템플릿으로 하면 다양한 방법으로 확인 가능합니다.!


	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;


	// auto 추론은 템플릿 추론과 동일하니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// T a1 = n; 이므로 규칙1.  적용
	//		=> 우변의 const, volatiole, reference 제거 후 auto 타입 결정



	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int 
	auto a4 = cr; // a4 : int

	// T& a5 = n 이므로 규칙 2. 적용
	// 				=> 우변의 reference 속성만 제거

	auto& a5 = n;  // auto :  int   a5 : int&
	auto& a6 = r; // auto: int	a5: int&
	auto& a7 = c; 	// auto: const int, a7: const in&
	auto& a8 = cr;	// auto : const int, a8: const int&a
}


// auto는 pretty 같이 출력 포맷 알려주는 매크로는 없나요?
// => C++ 표준에는 없고, boost 라이브러리의 type_name 이라는 클래스로 출력 가능합니다.

