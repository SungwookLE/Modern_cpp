// decltype Ÿ�� �߷� - 71page




int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;





	// decltype 추론 규칙 1. () 안에 심볼의 이름만 있을 때
	// => 해당 심볼의 선언을 보고 동일한 타입으로 결정

	decltype(n) d1; // int d1;
	decltype(r) d2; // int& d2; 초기값이 없기 때문에 에러
	decltype(c) d3; // const int d3; 초기값이 없기 때문에 에러
	decltype(p) d4; // int* d4;

	// auto 와의 차이점
	auto a = r; // int a = r;
	decltype(r) d; // int& d;
	
}