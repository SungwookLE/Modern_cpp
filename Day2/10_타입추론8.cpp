// decltype ��Ģ 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// 심볼의 이름만 있는 경우 - 규칙1
	decltype(p)		d1; // int* d1;

	// 규칙 2. ()안에 심볼의 이름과 연산자 등을 포함한 표현식이 있을 때
	// => 표현식이 등호의 왼쪽에(lvalue) 올 수 있다면 참조 타입
	// => 올 수 없다면 값 타입
	decltype(*p)	d2;  // *p = 0 이 가능. int& d2
							// 		초기값 없어서 에러
	decltype(x[0])	d3;  // "x[0] = 0" 가능, int& d3; 근데 초기값 없어서 에러


	decltype(n) d; // "n=0" 가능하지만, ()안에 심볼의 이름만 있으므로 규칙 1. 적용하므로, int d
					

	decltype(n + n) d4;  // "n+n = 10" 이 안되므로 값타입
							// int d4;
	
	decltype(++n)   d5;  // "++n = 10" 은 에러가 압니다.
						// 등호의 왼쪽에 올 수 있는 표현식!
						// int& d5


						
						
	decltype(n++)   d6;  // "n++ = 10" 은 에러. ..
						// 등호의 왼족에 올 수 없는 표현식 이므로, 값 타입(int&가 아닌 int)
						// int d6;
	
	// auto와 decltype
	int y[3] = {1,2,3};

	auto a = y[0];		
						// auto는 int 로 결정
						// int a = y[0]

	deecltype(y[0]) d; // int& d;

			
}

