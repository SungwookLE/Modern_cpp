// C++98 초기화의 문제점 - 54p
#include <complex>
#include <vector>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);

	// 2. 동적 할당한 배열을 초기화 할수 없다.
	int* p = new int[3];

	// 3. 1-10으로 초기화된 vector를 만들 수 없다.
	std::vector<int> v(10,2); // 10개를 2로

}
class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할 수 없다.
	int x[3];
};



