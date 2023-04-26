// 91 page
int main()
{
	int n = 10;

	// 포인터의 포인터(2중 포인터)를 만들 수 있습니다.
	int *p = &n;
	int* *pp = &p; // ok

	// 레퍼런스의 레퍼런스를 직접 코딩으로 만들 수 없습니다.
	int& r = n;
	int& &rr = r; // error


	using LREF = int&; 
	using RREF = int&&;

	// 컴파일 과정에서 레퍼런스의 레퍼런스는 에러가 아닙니다.
	// => reference collapsing 규칙으로 계산됩니다.

	// reference collapsing
	LREF& r3 = n ;	// int&	&		=> int&
	RREF& r4 = n ;	// int&& &		=> int&
	LREF&& r5 = n ; // int& &&		=> int&
	RREF&& r6 = 3;	// int&& &&		=> int&&
}

// reference collapsing 은 아래처럼 템플릿에서 자주 발생.
template<typename T> void foo(T a)
{
	T& r = a; // 아래 처럼 사용했을 때 r의 타입을 생각해보세요
				// int& & r = a; -> collapsing 규칙에 의해,
				// int& r = a;
}

int n = 0;
foo<int&>(n);




