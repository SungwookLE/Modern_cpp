#include <complex>

int main()
{
	// C+98: 변수에 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// c+11: 모든 변수를 동일한 방법으로 초기화 할 수 있다.
	// 일관된 초기화 (uniform initialization)
	// => 흔히, 중괄호 초기화 (brace init)
	int n2 = {10};
	int x2[2] = { 1,2 };
	std::complex<double> c2 = {1,2};

	// direct(직접) initialization : =이 없는 것
	// copy(복사) 	initialization : =이 있는 것
	int n3{10};
	int x3[2]{ 1,2 };
	std::complex<double> c2{1,2};

	



}












